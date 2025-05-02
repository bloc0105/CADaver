extends Node

@export var drawingScene : PackedScene

func _ready() -> void:
	Hub.new_drawing.connect(on_new_drawing)

func on_new_drawing() -> void:
	var newOne := Drawing.new()
	newOne.draw_name = "new"
	Hub.drawings.append(newOne);
	Hub.currentDrawing = newOne
	
	var newScene := drawingScene.instantiate() as DrawingScene
	newScene.drawing = newOne
	Hub.drawings_container.add_child(newScene)
	
	Hub.drawings_changed.emit()
	Hub.current_drawing_changed.emit()
	
