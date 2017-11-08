#include "SDL2/SDL.h"
#include  <jack/jack.h>





jack_port_t *midiout;

int main() {


SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_EVENTS | SDL_INIT_JOYSTICK);
SDL_Event event;



printf("\n nb of joystick %i", SDL_NumJoysticks());
SDL_Joystick *joy;
SDL_JoystickGUID joyguid;
joy = SDL_JoystickOpen(0);
joyguid = SDL_JoystickGetGUID(joy);
if (joy) {
printf("Opened Joystick 0\n");
printf("Name: %s\n", SDL_JoystickNameForIndex(0));
printf("Number of Axes: %d\n", SDL_JoystickNumAxes(joy));
printf("Number of Buttons: %d\n", SDL_JoystickNumButtons(joy));
printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
printf("Number of POV Hats : %d\n", SDL_JoystickNumHats(joy));
} else {


printf("Couldn't open Joystick 0\n");
}

    while(event.type != SDL_QUIT)
{
   

   switch (event.type) {
       case SDL_JOYAXISMOTION:
           if(!event.jaxis.axis >23) {
           printf("\n Motion of axis %i now at %i", event.jaxis.axis, event.jaxis.value);
           }
           //event.type = NULL;

           break;
       case SDL_JOYHATMOTION:
           printf("\n Hat  %i now at %i", event.jhat.hat, event.jhat.value);
           //event.type = NULL;
           break;
       case SDL_JOYBUTTONDOWN:
           printf ("\n Button %i pressed", event.jbutton.button);
           //event.type = NULL;
           break;
       default:
            break;
   }
   SDL_WaitEvent(&event);

}
return 0;
}
