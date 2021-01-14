# DrawPixels
[Defold](https://defold.com/) Native extension for drawing pixels and simple geometry into texture buffer. Functions from the original AGG (written in C++) has been exposed to Lua to use in Defold. 



## To install the library: 
Simply open the [game.project](https://defold.com/manuals/project-settings/) setting file, and add the below link on the dependencies field: 

> https://github.com/dotgears/DefoldExtension_DrawPixelsAGG/archive/master.zip

## Set-up: 

##### Initially, a `buffer_info` table must be defined, which contains: 

`buffer`: Use [buffer.create](https://defold.com/ref/buffer/#buffer.create:element_count-declaration) to declare the buffer. 

`width` : How wide the drawing scene is. 

`height`: How high the drawing scene is. 

`channel`: This is set as 3 if you use RGB, and 4 for RGBA.  


## Exposed functions: 

- #### `drawpixels.setup(buffer_info)`: Setup to use the drawpixels. Take the buffer_info declared above as input. 

- #### `drawpixels.destroy()`: Destroy all what have been drawn. 

- #### `drawpixels.clear(r,g,b,a)`: 


- #### `drawpixels.setLineWidth(Line_width)`: 

  - `Line_width`: Set line width

- #### `drawpixels.setLineColor(r,g,b,a)`: 

  - Set line color using RGBA color code.

- #### `drawpixels.moveTo(x,y)`: 

  - Move the draw cursor to position `(x,y)`.

- #### `drawpixels.lineTo(x,y)`: 

From the current position of the cursor, draw a line to `(x,y)`. 

- #### `drawpixels.drawPath()`:

- #### `drawpixels.removePath()`: 

- #### `drawpixels.triangle(x1,y1,x2,y2,x3,y3)`:

  - A triangle will be draw starting from point `(x1,y1)` to `(x3,y3)`. 

- #### `drawpixels.rectangle(x1,y1,x2,y2)`:

  - `x1` and `y1`: Position of bottom-left point of the rectangle. 

  - `x2` and `y2`: Position of the top-right point of the rectangle. 

- #### `drawpixels.ellipse(cx,cy,rx,ry)`: 

  - `cx` and `cy`: Center position of the ellipse. 

  - `rx`: Horizontal radius of the ellipse. 

  - `ry`: Vertical radius of the ellipse. 

- #### `drawpixels.arc(cx,cy,rx,ry,start,sweep)`: 
 
  - `cx` and `cy`: Center position of the arc. 

  - `rx`: Horizontal radius of the arc. 

  - `ry`: Vertical radius of the arc. 
  
  - `start`: Starting  of the arc. 
  
  - `sweep`: Sweeping  of the arc, in pi. 
 
- #### `drawpixels.star(cx,cy,rx,ry,startAngle,numRays)`: 

  - `cx` and `cy`: Center position of the star. 

  - `rx`: Horizontal radius of the star. 

  - `ry`: Vertical radius of the star. 
  
- #### `drawpixels.roundedRect(x1,y1,x2,y2,r)

  - `x1` and `y1`: Position of bottom-left point of the rectangle. 

  - `x2` and `y2`: Position of the top-right point of the rectangle. 
  
  - `r`: radius of the rounded circle at the edge. 
  
- #### `drawpixels.curve(x1,y1,x2,y2,x3,y3)


  
  




















