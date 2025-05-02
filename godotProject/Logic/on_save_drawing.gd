extends Node

@export var drawingScene : PackedScene

func _ready() -> void:
	Hub.save_drawing.connect(on_save_drawing)

func on_save_drawing(index) -> void:
	var d := Hub.drawings[index]
	if (!d.dirty):
		return
		
	d.dirty = false
	Hub.dirty_changed.emit()
