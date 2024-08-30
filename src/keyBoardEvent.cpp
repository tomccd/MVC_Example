#include <iostream>
#include<SDL2/SDL.h>
/*
    SDL_KEYDOWN: Kiểm tra 1 nút bất kì được nhấn -->SDL_Event.type
        SDL_KEYUP: kiểm tra 1 nút bất kì được nhả ra -->SDL_Event.type
        SDKL_a: kiểm tra phím 'a' được nhấn
        --> sử dung SDK_Event.key.keysym.sym để kiểm tra xem nút nào được nhấn

    SDL_MOUSEBUTTONDOWN: kiểm tra chuột có được nhấn hay không -->SDL_Event.type
        SDL_BUTTON_LEFT: chuột trái được nhấn
        SDL_BUTTON_RIGHT: chuột phải được nhấn
        SDL_BUTTON_MIDDLE: chuột giữa được nhấn
        --> SDL_Event.button.button
    
    <===> Tương tự với SDL_MOUSEBUTTONUP

    SDL_MOUSEWHEEL: kiểm tra bánh xe ở chuột có được lăn hay không -->SDL_Event.type
        SDL_Event.wheel.y > 0: lăn lên
        SDL_Event.wheel.y < 0: lăn xuống
        SDL_Event.wheel.x > 0: lăn phải
        SDL_Event.wheel.x < 0: lăn trái        

*/
const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char* argv[]){

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<std::endl;
    }

    SDL_Window* window = SDL_CreateWindow("Test keyboard",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    if(NULL==window){
        std::cout<<"Could not create window: "<<SDL_GetError()<<std::endl;
        return 1;
    }
    SDL_Event windowEvent;
    while(true){
        if(SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }

            if(SDL_MOUSEMOTION == windowEvent.type){
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout<<x<<" : "<<y<<std::endl;
            }

            if(SDL_MOUSEBUTTONDOWN == windowEvent.type){

                if(SDL_BUTTON_LEFT==windowEvent.button.button){
                    std::cout<<"Left mouse button is down"<<std::endl;
                }
                else if(SDL_BUTTON_RIGHT == windowEvent.button.button){
                    std::cout<<"Right mouse button is down"<<std::endl;                    
                }
                else if( SDL_BUTTON_MIDDLE == windowEvent.button.button){
                    std::cout<<"Middle mouse button is down"<<std::endl;        
                }
            }

            if(SDL_MOUSEBUTTONUP == windowEvent.type){

                if(SDL_BUTTON_LEFT==windowEvent.button.button){
                    std::cout<<"Left mouse button is up"<<std::endl;
                }
                else if(SDL_BUTTON_RIGHT == windowEvent.button.button){
                    std::cout<<"Right mouse button is up"<<std::endl;                    
                }
                else if( SDL_BUTTON_MIDDLE == windowEvent.button.button){
                    std::cout<<"Middle mouse button is up"<<std::endl;        
                }
            }

            if(SDL_MOUSEWHEEL==windowEvent.type){
                if(windowEvent.wheel.y>0) std::cout <<"Mouse wheel is scrolling up" <<std::endl;
                else if (windowEvent.wheel.y<0) std::cout<< "Mouse wheel is scrolling down" <<std::endl;
                else if (windowEvent.wheel.x>0) std::cout<< "Mouse wheel is scrolling right" <<std::endl;
                else if (windowEvent.wheel.x<0) std::cout<< "Mouse wheel is scrolling left" <<std::endl;
            }
            if(SDL_KEYDOWN == windowEvent.type){
                //std::cout<<"Key is down"<<std::endl;
                if(SDLK_a == windowEvent.key.keysym.sym){
                    std::cout<<"A is down - Move left"<<std::endl;
                }
                else if(SDLK_s == windowEvent.key.keysym.sym){
                    std::cout<<"B is down - Move down"<<std::endl;
                }
                else if(SDLK_d == windowEvent.key.keysym.sym){
                    std::cout<<"D is down - Move right"<<std::endl;
                }                
                else if(SDLK_w == windowEvent.key.keysym.sym){
                    std::cout<<"W is down - Move up"<<std::endl;
                }
            }
            else if (SDL_KEYUP==windowEvent.type){
                if(SDLK_a == windowEvent.key.keysym.sym){
                    std::cout<<"A is down - Move stop"<<std::endl;
                }
                else if(SDLK_s == windowEvent.key.keysym.sym){
                    std::cout<<"B is down - Move stop"<<std::endl;
                }
                else if(SDLK_d == windowEvent.key.keysym.sym){
                    std::cout<<"D is down - Move stop"<<std::endl;
                }                
                else if(SDLK_w == windowEvent.key.keysym.sym){
                    std::cout<<"W is down - Move stop"<<std::endl;
                }
            }

        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}