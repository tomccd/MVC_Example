#include  "../header/MVC_Manage_Folder.hpp"

int main(){
    Manage_Folder_Controller controller(new Manage_Folder_Model,new Manage_Folder_View);
    std::string path;
    while(1){
        std::cout << "\n---------------------------------\n";
        std::cout  << "Enter 1: Default\n";
        std::cout << "Enter 2: List Files with given directory\n";
        std::cout  << "Your choice: ";
        int option;
        std::cin >>option;
        switch(option){
            case 1:
                controller.updateView();
                break;
            case 2:
                std::cout << "\n---------------------------------\n";
                std::cout << "Enter Dir: ";
                std::cin >> path;
                controller.setPath(path);
                controller.updateView();
                break;
        }
    }
}