#include "LoadFileDialog.h"

#include "Library/Util/LoadFileDialog.h"

namespace godot
{
    void LoadFileDialog::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("is_canceled"), &LoadFileDialog::isCanceled);
        ClassDB::bind_method(D_METHOD("execute"), &LoadFileDialog::execute);
        ClassDB::bind_method(D_METHOD("add_filter", "name", "comma_list_of_suffixes"), &LoadFileDialog::addFilter);
        ClassDB::bind_method(D_METHOD("set_path", "default_path"), &LoadFileDialog::setPath);
        ClassDB::bind_method(D_METHOD("get_result_path"), &LoadFileDialog::getResultPath);
    }

    LoadFileDialog::LoadFileDialog()
    {
        dlg = std::make_unique<Library::LoadFileDialog>();
    }

    LoadFileDialog::~LoadFileDialog() {}

    void LoadFileDialog::setPath(const godot::String& p) {
        dlg->setDefaultPath(std::string(p.utf8()));
    }

    void LoadFileDialog::addFilter(const godot::String& name, TypedArray<godot::String> suffixes)
    {
        std::string n = std::string(name.utf8());
        std::vector<std::string> s;
        for (size_t i = 0; i < suffixes.size(); i++)
        {
            godot::String suf = suffixes[i];
            s.push_back(std::string(suf.utf8()));
        }
        dlg->addFilter(n, s);
    }

    bool LoadFileDialog::isCanceled()
    {
        return dlg->isCancled();
    }

    void LoadFileDialog::execute()
    {
        dlg->execute();
    }

    godot::String LoadFileDialog::getResultPath() const
    {
        return dlg->getResultPath().c_str();
    }
}