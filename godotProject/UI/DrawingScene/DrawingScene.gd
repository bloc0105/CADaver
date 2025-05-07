class_name DrawingScene extends Control

@onready var camera : Camera3D = $FreeLookCamera
@onready var child_pool : Node = $ChildPool

var cad_vis : PackedScene = preload("res://3D/CADObject/CADVisualization.tscn")

var drawing : Drawing = null;

func _ready()->void:
	pass

func _on_dirtymaker_pressed() -> void:
	if (drawing and not drawing.dirty):
		drawing.dirty = true;
		Hub.file.dirty_changed.emit();
	
func reset_children()->void:
	for n in child_pool.get_children():
		child_pool.remove_child(n)
		n.queue_free()
		
func _on_tab_bar_drawing_changed(index: Variant) -> void:
	if (!child_pool):
		return;
	reset_children()
	if (index != -1):
		var drawing := Hub.file.drawings[index]
		var vis := cad_vis.instantiate() as CADVisualization
		child_pool.add_child(vis)
		vis.set_drawing(drawing)		
		
