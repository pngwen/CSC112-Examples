// A simple shape drawing application.
// This simply creates an applicaiton, adds the canvas to it, and then
// waits for the eventLoop to exit.
#include <iostream>
#include "term.h"
#include "application.h"
#include "canvas.h"

using namespace std;

int main()
{
    Application *app;
    Canvas *canvas;

    app = new Application();
    canvas = new Canvas();
    app->child(canvas);

    app->eventLoop();

    cout << cursorOn << endl;
    return 0;
}
