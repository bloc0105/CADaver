#include "SaveFileDialog.h"

#include "Library/Util/SaveFileDialog.h"

namespace godot
{
    void SaveFileDialog::_bind_methods()
    {
        ClassDB::bind_method(D_METHOD("is_canceled"), &SaveFileDialog::isCanceled);
        ClassDB::bind_method(D_METHOD("execute"), &SaveFileDialog::execute);
        ClassDB::bind_method(D_METHOD("add_filter", "name", "comma_list_of_suffixes"), &SaveFileDialog::addFilter);
        ClassDB::bind_method(D_METHOD("set_path", "default_path"), &SaveFileDialog::setPath);
        ClassDB::bind_method(D_METHOD("set_save_file_name", "save_file_name"), &SaveFileDialog::setSaveFileName);
        ClassDB::bind_method(D_METHOD("get_result_path"), &SaveFileDialog::getResultPath);
    }

    SaveFileDialog::SaveFileDialog()
    {
        dlg = std::make_unique<Library::SaveFileDialog>();
    }

    SaveFileDialog::~SaveFileDialog() {}

    void SaveFileDialog::setPath(const godot::String& p)
    {
        dlg->setDefaultPath(std::string(p.utf8()));
    }

    void SaveFileDialog::addFilter(const godot::String& name, TypedArray<godot::String> suffixes)
    {
        std::string              n = std::string(name.utf8());
        std::vector<std::string> s;
        for (size_t i = 0; i < suffixes.size(); i++)
        {
            godot::String suf = suffixes[i];
            s.push_back(std::string(suf.utf8()));
        }
        dlg->addFilter(n, s);
    }

    bool SaveFileDialog::isCanceled()
    {
        return dlg->isCancled();
    }

    void SaveFileDialog::execute()
    {
        dlg->execute();
    }

    void SaveFileDialog::setSaveFileName(const godot::String& f)
    {
        dlg->setSaveFileName(std::string(f.utf8()));
    }

    godot::String SaveFileDialog::getResultPath() const
    {
        return dlg->getResultPath().c_str();
    }
}