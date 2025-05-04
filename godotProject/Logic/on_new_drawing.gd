extends Node

@export var drawingScene : PackedScene

func _ready() -> void:
	Hub.file.new_drawing.connect(on_new_drawing)

func on_new_drawing() -> void:
	var newOne := Drawing.new()
	newOne.draw_name = "new"
	Hub.file.drawings.append(newOne);
	Hub.file.currentDrawing = newOne
	
	var newScene := drawingScene.instantiate() as DrawingScene
	newScene.drawing = newOne
	Hub.drawings_container.add_child(newScene)
	
	Hub.file.drawings_changed.emit()
	Hub.file.current_drawing_changed.emit()
	
