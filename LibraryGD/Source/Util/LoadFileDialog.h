#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <memory>

namespace Library
{
    class LoadFileDialog;
}

namespace godot
{
    class LoadFileDialog : public RefCounted
    {
        GDCLASS(LoadFileDialog, RefCounted)

      protected:
        static void _bind_methods();

      public:
        LoadFileDialog();
        virtual ~LoadFileDialog();

      private:
        void setPath(const godot::String&);
        void addFilter(const godot::String&, TypedArray<godot::String>);
        bool isCanceled();
        void execute();

        std::unique_ptr<Library::LoadFileDialog> dlg; 
    };
}