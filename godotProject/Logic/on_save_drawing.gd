extends Node

var currentDrawing : Drawing;

func _ready() -> void:
	Hub.file.save_drawing.connect(on_save_drawing)

func on_save_drawing(index) -> void:
	var d := Hub.file.drawings[index]
	currentDrawing = d
	invokeSaveFileDialog()

func invokeSaveFileDialog():
	var dlg = SaveFileDialog.new()
	dlg.add_filter("Step File", ["stp","step"])
	dlg.set_save_file_name(currentDrawing.draw_name + ".step");
	dlg.set_path(path_util.get_path_without_filename(currentDrawing.save_path));
	dlg.execute();
	
	if (!dlg.is_canceled()):
		currentDrawing.shape.save_cad_to_file(dlg.get_result_path())
		currentDrawing.dirty = false
		currentDrawing.name = path_util.get_file_name_without_extension(dlg.get_result_path());
		Hub.file.dirty_changed.emit()
