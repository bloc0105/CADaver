class_name view_cube extends MeshInstance3D

signal transformation_changed(trans : Transform3D)

@export var sensitivity: float = 0.01

var is_dragging: bool = false
var last_mouse_pos: Vector2
var there_was_motion : bool = false

func _input(event):
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				is_dragging = true
				last_mouse_pos = event.position
				there_was_motion = false
			else:
				is_dragging = false
				if (!there_was_motion):
					var col := pick(event.position)
					print(col)
	if event is InputEventMouseMotion and is_dragging:
		there_was_motion = true
		var current_mouse_pos = event.position
		var delta : Vector2 = current_mouse_pos - last_mouse_pos
		last_mouse_pos = current_mouse_pos
		rotate_y(delta.x * sensitivity)
		rotate_x(delta.y * sensitivity)
		if(delta.length_squared()>0):
			transformation_changed.emit(transform)
		
func pick(pos : Vector2) -> Node:
	var viewport = get_viewport()
	var mouse_position = pos
	var ray_origin = viewport.get_camera_3d().project_ray_origin(mouse_position)
	var ray_direction = viewport.get_camera_3d().project_ray_normal(mouse_position)
	var space_state = get_world_3d().direct_space_state
	var query_parameters = PhysicsRayQueryParameters3D.new()
	query_parameters.from = ray_origin
	query_parameters.to = ray_origin + ray_direction * 1000 # Raycast 1000 Einheiten weit
	var result = space_state.intersect_ray(query_parameters)
	if result and result.collider:
		return result.collider
	return null
