## About Anti-Grain Geometry Library (AGG) 

AGG is a 2D, open source rendering library written by Maxim Shemanarev in C++. It is not fully a graphic library - in other words it is a rendering engine that produdces pixel images in meory from some vectorial data. 

Key advantages of AGG includes Anti-Aliasing and Subpixel Accuracy rendering, and high quality, high performance with lightweight design and flexibility. For more information, please visit [the AGG Project](http://agg.sourceforge.net/antigrain.com/index.html) Website. 


# DrawPixels

[Defold](https://defold.com/) native extension for drawing pixels and simple geometry into texture buffer. Functions from the original AGG (written in C++) has been exposed to Lua to use in Defold. The current version is build based on [AGG 2.6](https://github.com/ghaerr/agg-2.6) by Gregory Haerr. 


## To install the library: 
Simply open the [game.project](https://defold.com/manuals/project-settings/) setting file, and add the below link on the dependencies field: 

> https://github.com/dotgears/DefoldExtension_DrawPixelsAGG/archive/master.zip

From "Project" menu in the taskbar, click "Fetch Libraries" to fetch the dependencies added above. 

## Exposed functions: 

- #### `drawpixels.setup(buffer_info)`: 
  - Setup to use the drawpixels. Take the buffer_info declared above as input. 

- #### `drawpixels.destroy()`: 
  - Destroy all what have been drawn. 

- #### `drawpixels.clear(r,g,b,a)`: 
  

- #### `drawpixels.setLineWidth(Line_width)`: 

  - `Line_width`: Set line width

- #### `drawpixels.setLineColor(r,g,b,a)`: 

  - Set line color using RGBA color code.

- #### `drawpixels.moveTo(x,y)`: 

  - Move the draw cursor to position `(x,y)`.

- #### `drawpixels.lineTo(x,y)`: 

   - From the current position of the cursor, draw a line to `(x,y)`. 

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
  
- #### `drawpixels.roundedRect(x1,y1,x2,y2,r)`:

  - `x1` and `y1`: Position of bottom-left point of the rectangle. 

  - `x2` and `y2`: Position of the top-right point of the rectangle. 
  
  - `r`: radius of the rounded circle at the edge. 
  
- #### `drawpixels.curve(x1,y1,x2,y2,x3,y3):`

  - Draw a [Bézier Curve](https://en.wikipedia.org/wiki/Bézier_curve) with three or four control points, depend on the input. 

  - `x1` and `y1`: Starting point/ First control point of the curve. 
    
  If there are three control points:    
  
  - `x2` and `y2`: Second control point. 
  
  - `x3` and `y3`: Ending point/ Third control point. 
  
  If there are four control points: 
  
  - `x2` and `y2`: Second control point. 
  
  - `x3` and `y3`: Third control point. 
  
  - `x4` and `y4`: Ending point/ Fourth control point. 
   
  
- #### `drawpixels.polygon(xy)`: 

  - `xy`: A table contains all the coordinate of the points in the polygon (Polygonal chain) , in the type of `{x1,y1,x2,y2,...,xn,yn)`. 
  
  - Draw a filled polygon, starting from the first point in `xy` and closed by connecting the last point to the first point. 

- #### `drawpixels.polyline(xy)`: 

  - `xy`: A table contains all the coordinate of the points in the polyline, in the type of `{x1,y1,x2,y2,...,xn,yn)`. 
  
  - Draw a polyline, starting from the first point and end with the last point in `xy` table, without filling or closing. 
  
  
  
  
## LICENSING: 


    Copyright (C) 2021 dotGEARS.
    Permission is granted to copy, distribute and/or modify this document
    under the terms of the GNU Free Documentation License, Version 1.3
    or any later version published by the Free Software Foundation;
    with no Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts.
    A copy of the license is included in the section entitled "GNU
    Free Documentation License".



  
  




















