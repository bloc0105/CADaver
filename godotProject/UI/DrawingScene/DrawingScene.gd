class_name DrawingScene extends Control

@onready var camera : Camera3D = $FreeLookCamera

var drawing : Drawing = null;

func _ready()->void:
	pass

func _on_dirtymaker_pressed() -> void:
	if (drawing and not drawing.dirty):
		drawing.dirty = true;
		Hub.file.dirty_changed.emit();

#func activate_if_enabled():
#	var active : bool= Hub.file.currentDrawing == drawing and drawing;
#	visible = active;
#	if (active):
#		camera.make_current()
	


func _on_drawing_changed(drawingIndex) -> void:
	pass
