//main function for our pong game
#include "pong.h"
#include "application.h"
#include "term.h"

using namespace std;

int main()
{
    Application *app;
    Pong *pong;

    //create an application widget
    app = new Application();

    //create pong and make it the application's child
    pong = new Pong();
    app->child(pong);

    //enter the event loop
    app->eventLoop();
}
