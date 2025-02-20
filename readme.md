# **Render Core** **|** **Documentation**

> Render Core still isn't released yet, but we are working on it.

## What it can do

Render Core can render 3D scenes in realtime.  
its also using shaders to render the scene.

## Examples

````c++
#include "RenderCore.h"

int main() {
    RenderCore* core = new RenderCore();
    core->init();
    core->createWindow(800, 600);
    core->run();

    return 0;
}
````

This example creates a window and runs the render loop.  
you can also do more with RenderCore.
  
  
you can render a scene with objects in realtime, it's very simple.

````c++
#include "RenderCore.h"

int main() {
    RenderCore* core = new RenderCore();

    scene* scene = core->createScene("shader.vert", 
        "shader.frag");

    object* object = scene->createObject("path/to/model.obj", 
        "texture.png", 
        Core::vec3(0, 0, 0), 
        Core::vec3(0, 0, 0), 
        Core::vec3(1, 1, 1));

    core->init();
    core->createWindow(800, 600);

    core->setActiveScene(scene);

    core->run();

    return 0;
}
````
  
this will render a scene with the model "path/to/model.obj" in it.  
you can also rotate the object, or change its position.  
and it will update in realtime.
  
you can find more examples in the examples folder.

## License

Render Core is released under the MIT License.

Copyright (c) 2025 TheSorceDev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
