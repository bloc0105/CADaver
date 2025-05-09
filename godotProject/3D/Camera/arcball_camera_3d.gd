extends Camera3D

@export var sensitivity: float = 0.005
@export var zoom_speed: float = 0.05


signal rotation_changed()

var zoom: float = 5.0
var camera_rotation : Transform3D;
var offset : Vector3;
var bounding_box : AABB;

var is_dragging: bool = false
var last_mouse_pos: Vector2


func _ready() -> void:
	size = zoom

func _process(_delta: float) -> void:
	pass

func _input(event):
	if event is InputEventMouseButton:
		if event.button_index == MOUSE_BUTTON_LEFT:
			if event.pressed:
				is_dragging = true
				last_mouse_pos = event.position
			else:
				is_dragging = false
		elif event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_WHEEL_UP:
			zoom = zoom * (1-zoom_speed);
			update_camera()
		elif event is InputEventMouseButton and event.button_index == MOUSE_BUTTON_WHEEL_DOWN:
			zoom = zoom * (1+zoom_speed);
			update_camera()
	if event is InputEventMouseMotion and is_dragging:
		var current_mouse_pos = event.position
		var delta : Vector2 = current_mouse_pos - last_mouse_pos
		last_mouse_pos = current_mouse_pos
		camera_rotation = camera_rotation.rotated_local(Vector3(0,1,0),-delta.x * sensitivity)
		camera_rotation = camera_rotation.rotated_local(Vector3(1,0,0),-delta.y * sensitivity)
		update_camera()
		rotation_changed.emit()
		
func _on_view_cube_transform_changed(trans: Transform3D) -> void:
	camera_rotation = trans
	update_camera()
	
func update_camera()->void:
		transform = Transform3D.IDENTITY.translated(offset)*camera_rotation*Transform3D.IDENTITY.translated(Vector3(0,0,zoom))
		size = zoom
		look_at(offset,camera_rotation.basis.y)

func set_aabb(aabb : AABB)->void:
	bounding_box = aabb;
	offset= bounding_box.get_center()
	zoom = bounding_box.get_longest_axis_size()
	update_camera()
	
