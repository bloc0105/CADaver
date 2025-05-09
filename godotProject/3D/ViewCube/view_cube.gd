class_name view_cube extends MeshInstance3D

signal transformation_changed(trans : Transform3D)

@export var sensitivity: float = 0.01

var is_dragging: bool = false
var last_mouse_pos: Vector2

func _input(event):
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				is_dragging = true
				last_mouse_pos = event.position
			else:
				is_dragging = false
	if event is InputEventMouseMotion and is_dragging:
		var current_mouse_pos = event.position
		var delta : Vector2 = current_mouse_pos - last_mouse_pos
		last_mouse_pos = current_mouse_pos
		rotate_y(delta.x * sensitivity)
		rotate_x(delta.y * sensitivity)
		if(delta.length_squared()>0):
			transformation_changed.emit(transform)
		
		
