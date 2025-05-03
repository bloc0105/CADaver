#pragma once

#include <godot_cpp/classes/node3d.hpp>
#include <memory>

namespace Library
{
    class SaveFileDialog;
}

namespace godot
{
    class SaveFileDialog : public RefCounted
    {
        GDCLASS(SaveFileDialog, RefCounted)

      protected:
        static void _bind_methods();

      public:
        SaveFileDialog();
        virtual ~SaveFileDialog();

      private:
        void setPath(const godot::String&);
        void setSaveFileName(const godot::String&);
        void addFilter(const godot::String&, TypedArray<godot::String>);
        bool isCanceled();
        void execute();

        std::unique_ptr<Library::SaveFileDialog> dlg;
    };
}