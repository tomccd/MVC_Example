#ifndef __MVC__
#define __MVC__

#include <experimental/filesystem>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
namespace fs=std::experimental::filesystem;

/*Model*/
class Manage_Folder_Model{
    private:
        std::vector<std::string *>vct_path;
    public:
        std::vector<std::string *>getFiles(const std::string path);
};

/*View*/
class Manage_Folder_View{
    public:
        void displayFiles(std::vector<std::string *> vct_path) const;
};


/*Controller*/
class Manage_Folder_Controller{
    private:
        Manage_Folder_Model *model;
        Manage_Folder_View *view;
        std::string path;
    public:
        Manage_Folder_Controller(Manage_Folder_Model *_model, Manage_Folder_View *_view,std::string _path=fs::current_path()){
            model = _model;
            view = _view;
            path = _path;
        }
        void setPath(std::string _path);
        void updateView() const;
};
#endif
