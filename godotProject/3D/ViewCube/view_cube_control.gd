extends Control


@export var cam : Camera3D 

@onready var cube : Node3D = $VBoxContainer/SubViewportContainer/SubViewport/ViewCube


func _ready() -> void:
	pass

func _process(_delta: float) -> void:
	var trans := cam.transform.inverse()
	trans = trans.translated(-trans.origin)
	cube.transform = trans
