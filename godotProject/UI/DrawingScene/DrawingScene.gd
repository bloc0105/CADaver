class_name DrawingScene extends Control

var drawing : Drawing = null;

func _ready()->void:
	Hub.current_drawing_changed.connect(activate_if_enabled)

func _on_dirtymaker_pressed() -> void:
	if (drawing and not drawing.dirty):
		drawing.dirty = true
		Hub.dirty_changed.emit()

func activate_if_enabled():
	visible = Hub.currentDrawing == drawing and drawing
	
