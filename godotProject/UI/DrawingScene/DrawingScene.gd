class_name DrawingScene extends Control

@onready var camera : Camera3D = $FreeLookCamera
@onready var cad : CADObject = $CADObject

var drawing : Drawing = null;

func _ready()->void:
	pass

func _on_dirtymaker_pressed() -> void:
	if (drawing and not drawing.dirty):
		drawing.dirty = true;
		Hub.file.dirty_changed.emit();
	
func _on_tab_bar_drawing_changed(index: Variant) -> void:
	if (!cad):
		return
	if (index != -1):
		cad.set_drawing(Hub.file.drawings[index])
	else:
		cad.clear_drawing();
