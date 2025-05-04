extends Node

@export var drawingScene : PackedScene

func _ready() -> void:
	Hub.file.load_drawing.connect(on_load_drawing)

func on_load_drawing() -> void:
	var dlg = LoadFileDialog.new()
	dlg.add_filter("Step File", ["stp","step"])
	dlg.execute()
	
	if (!dlg.is_canceled()):
		var newOne := Drawing.new()
		newOne.draw_name =  path_util.get_file_name_without_extension(dlg.get_result_path());
		newOne.save_path = dlg.get_result_path();
		var success : bool = newOne.load_from_step_file();
		if (!success):
			OKPopup.make("Loading failed");
			return;
		Hub.file.drawings.append(newOne);
		Hub.file.currentDrawing = newOne

		var newScene := drawingScene.instantiate() as DrawingScene
		newScene.drawing = newOne
		Hub.drawings_container.add_child(newScene)
		
		Hub.file.drawings_changed.emit()
		Hub.current_drawing_changed.emit()
		
		
