extends Node

@export var drawingScene : PackedScene

func _ready() -> void:
	Hub.load_drawing.connect(on_load_drawing)

func on_load_drawing() -> void:
	var dlg = LoadFileDialog.new()
	dlg.add_filter("Step File", ["stp","step"])
	dlg.execute()
	
	if (!dlg.is_canceled()):
		var newOne := Drawing.new()
		newOne.draw_name =  path_util.get_file_name_without_extension(dlg.get_result_path());
		Hub.drawings.append(newOne);
		Hub.currentDrawing = newOne

		var newScene := drawingScene.instantiate() as DrawingScene
		newScene.drawing = newOne
		Hub.drawings_container.add_child(newScene)
		
		Hub.drawings_changed.emit()
		Hub.current_drawing_changed.emit()
		
		
