// Extension lib defines
#if !defined(DM_HEADLESS)
#define LIB_NAME "DrawPixels"
#define MODULE_NAME "drawpixels"

#define DLIB_LOG_DOMAIN LIB_NAME
#define M_PI 3.14159265358979323846

#include <dmsdk/sdk.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

#include "agg2d.h"

struct BufferInfo
{
	dmBuffer::HBuffer buffer;
	int width;
	int height;
	int channels;
	bool premultiply_alpha;
	uint8_t *bytes;
	uint32_t src_size;
};

BufferInfo buffer_info;

static int offset_x = 0;
static int offset_y = 0;

static Agg2D *mAgg = NULL;

static void read_and_validate_buffer_info(lua_State *L, int index)
{
	luaL_checktype(L, index, LUA_TTABLE);
	lua_getfield(L, index, "buffer");
	lua_getfield(L, index, "width");
	lua_getfield(L, index, "height");
	lua_getfield(L, index, "channels");
	lua_getfield(L, index, "premultiply_alpha");
	dmScript::LuaHBuffer *lua_buffer = dmScript::CheckBuffer(L, -5);
	buffer_info.buffer = lua_buffer->m_Buffer;

	if (!dmBuffer::IsBufferValid(buffer_info.buffer))
	{
		luaL_error(L, "Buffer is invalid");
	}

	dmBuffer::Result result = dmBuffer::GetBytes(buffer_info.buffer, (void **)&buffer_info.bytes, &buffer_info.src_size);
	if (result != dmBuffer::RESULT_OK)
	{
		luaL_error(L, "Buffer is invalid");
	}

	buffer_info.width = lua_tointeger(L, -4);
	if (buffer_info.width == 0)
	{
		luaL_error(L, "'width' of the buffer should be an integer and > 0");
	}

	buffer_info.height = lua_tointeger(L, -3);
	if (buffer_info.height == 0)
	{
		luaL_error(L, "'height' of the buffer should be an integer and > 0");
	}

	buffer_info.channels = lua_tointeger(L, -2);
	if (buffer_info.channels == 0)
	{
		luaL_error(L, "'channels' of should be an integer and 3 or 4");
	}

	if (lua_isboolean(L, -1) == 1)
	{
		buffer_info.premultiply_alpha = lua_toboolean(L, -1);
	}
	else
	{
		buffer_info.premultiply_alpha = false;
	}

	offset_x = buffer_info.width * 0.5;
	offset_y = buffer_info.height * 0.5;
}

static int drawpixels_clear(lua_State *L)
{
	int top = lua_gettop(L);

	int32_t b = luaL_checknumber(L, 1);
	int32_t g = luaL_checknumber(L, 2);
	int32_t r = luaL_checknumber(L, 3);
	int32_t a = luaL_checknumber(L, 4);

	mAgg->clearAll(r, g, b, a);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_setup(lua_State *L)
{
	int top = lua_gettop(L) + 5;
	read_and_validate_buffer_info(L, 1);

	mAgg = new Agg2D();
	mAgg->attach(buffer_info.bytes, buffer_info.width, buffer_info.height, buffer_info.width * buffer_info.channels);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_destroy(lua_State *L)
{
	int top = lua_gettop(L);

	if (mAgg)
	{
		delete mAgg;
		mAgg = NULL;
	}

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_moveTo(lua_State *L)
{
	int top = lua_gettop(L);

	double x = luaL_checknumber(L, 1) + offset_x;
	double y = luaL_checknumber(L, 2) + offset_y;

	mAgg->moveTo(x, y);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_lineTo(lua_State *L)
{
	int top = lua_gettop(L);

	double x = luaL_checknumber(L, 1) + offset_x;
	double y = luaL_checknumber(L, 2) + offset_y;

	mAgg->lineTo(x, y);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_drawPath(lua_State *L)
{
	int top = lua_gettop(L);

	mAgg->drawPath(Agg2D::StrokeOnly);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_removePath(lua_State *L)
{
	int top = lua_gettop(L);

	mAgg->resetPath();

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_setLineWidth(lua_State *L)
{
	int top = lua_gettop(L);

	double line_width = luaL_checknumber(L, 1);
	mAgg->lineWidth(line_width);

	assert(top == lua_gettop(L));
	return 0;
}

static int drawpixels_setLineColor(lua_State *L)
{
	int top = lua_gettop(L);

	int32_t b = luaL_checknumber(L, 1);
	int32_t g = luaL_checknumber(L, 2);
	int32_t r = luaL_checknumber(L, 3);
	int32_t a = luaL_checknumber(L, 4);

	mAgg->lineColor(Agg2D::Color(r, g, b, a));

	assert(top == lua_gettop(L));
	return 0;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
	{
		{"setup", drawpixels_setup},
		{"destroy", drawpixels_destroy},

		{"clear", drawpixels_clear},
		{"setLineWidth", drawpixels_setLineWidth},
		{"setLineColor", drawpixels_setLineColor},
		{"moveTo", drawpixels_moveTo},
		{"lineTo", drawpixels_lineTo},
		{"drawPath", drawpixels_drawPath},
		{"removePath", drawpixels_removePath},

		{0, 0}};

static void LuaInit(lua_State *L)
{
	int top = lua_gettop(L);
	luaL_register(L, MODULE_NAME, Module_methods);
	lua_pop(L, 1);
	assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeDrawPixelsExtension(dmExtension::AppParams *params)
{
	return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeDrawPixelsExtension(dmExtension::Params *params)
{
	LuaInit(params->m_L);
	printf("Registered %s Extension\n", MODULE_NAME);
	return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeDrawPixelsExtension(dmExtension::AppParams *params)
{
	return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeDrawPixelsExtension(dmExtension::Params *params)
{
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(DrawPixels, LIB_NAME, AppInitializeDrawPixelsExtension, AppFinalizeDrawPixelsExtension, InitializeDrawPixelsExtension, 0, 0, FinalizeDrawPixelsExtension)
#else

// dummy implementation
extern "C" void DrawPixels() {}

#endif