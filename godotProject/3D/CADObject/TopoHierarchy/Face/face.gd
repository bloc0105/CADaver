class_name face_scene extends Node3D

@onready var mesh : MeshInstance3D = $Mesh

var face : CADFace;


func _ready()->void:
	var cadmesh = face.get_cad_triangulation(0.1)
	mesh.mesh = cadmesh
