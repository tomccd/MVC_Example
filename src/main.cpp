#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char*argv[]){

    SDL_Surface *imageSurface =NULL;
    SDL_Surface *windowSurface = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"SDL could not initialize! SDL Error: "<<SDL_GetError()<<std::endl;
    }
    // Tao 1 cua so, 2 tham số WINDOWPOS có thể thay thế nếu như ta muốn window xuất hiện ở 1 vị trí cụ thể nào đó (x,y)
    // nếu là UNDEFINED thì nó sẽ xuất hiện random, là center thì nó xuất hiện ở giữa
    SDL_Window *window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    // Lấy bề mặt của 1 window đã được tạo trước đó
    windowSurface = SDL_GetWindowSurface(window);

    if(NULL == window){
        std::cout<<"Coudl not create window: "<<SDL_GetError()<<std::endl;
        return 1;
    }
    // Thêm màu cho window 
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,0);
    // 255, 0, 0, 255 tương ứng với Red Green Blue và độ trong suốt của background-> thiết lập màu săc
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 5);
    // Xóa các thiết lập trước đó
    SDL_RenderClear(renderer);
    // Hiển thị render mới 
    SDL_RenderPresent(renderer);

    // Khởi tạo cho những định dạng hình ảnh khác với bmp
    if(!(IMG_Init(IMG_INIT_PNG)&IMG_INIT_PNG)){
        std::cout<<"Could not initialize SDL_image: "<<IMG_GetError()<<std::endl;
    }
    
    // SDL_Event dung de lu tru su kien xay ra,<type union>
    SDL_Event windowEvent;
    // tải ảnh định dạng bit map vào biến imageSurface
    // imageSurface = SDL_LoadBMP("./Hello_World.bmp");
    imageSurface = IMG_Load("./test.png");
    if(NULL == imageSurface){
        std::cout<<"SDL could not load image! SDL Error: "<<SDL_GetError()<<std::endl;
    }
    while(true){
        //SDL_PollEvent dung de kiem tra xem co event nao xay ra khong, neu co tra ve True, khong tra ve False
        if(SDL_PollEvent(&windowEvent)){
            // SDL_QUIT tuong ung voi khi ta an x de tat chuong trinh 
            if(SDL_QUIT == windowEvent.type){
                break;
            }
            // Sao chép bề mặt của image lên bề mặt window -->dán ảnh
            SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
            // Cập nhật window
            SDL_UpdateWindowSurface(window);
        }
    }

    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(windowSurface);
    imageSurface = NULL;
    windowSurface=NULL;

    SDL_DestroyWindow(window);
    //SDL_Quit dung de dung hien thi cua so  
    SDL_Quit();
    return EXIT_SUCCESS; 
}