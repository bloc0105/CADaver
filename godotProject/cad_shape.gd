extends Node

@export var vertexScene : PackedScene;
@export var edgeScene : PackedScene;
@export var scalefactor : float = 0.1;

@onready var vertexOn : CheckBox = $VBoxContainer/Vertex
@onready var edgeOn : CheckBox = $VBoxContainer/Edge
@onready var wireOn : CheckBox = $VBoxContainer/Wire
@onready var faceOn : CheckBox = $VBoxContainer/Face
@onready var shellOn : CheckBox = $VBoxContainer/Shell
@onready var solidOn : CheckBox = $VBoxContainer/Solid
@onready var faceMeshOn : CheckBox = $VBoxContainer/FaceMesh
@onready var childPool : Node = $ChildPool
@onready var fileLocation : LineEdit = $VBoxContainer/FileLocation

var point_mesh;
var multi_mesh;
var points = []

func traversechilds(child : CADShape, depth):
	if (!child):
		return
	
	loadVertex(child)
	loadEdge(child)
	loadWire(child)
	loadFace(child)
	loadShell(child)
	loadSolid(child)
	loadFaceMesh(child)
	
	var childs = child.get_cad_children()
	for x in childs:
		traversechilds(x,depth+1)
	pass

func loadstp() -> void:
	var path = fileLocation.text
	var shape = CADShape.load_cad_from_file(path)
	traversechilds(shape,0);
	
	
func clearChilds() -> void:
	for n in childPool.get_children():
		childPool.remove_child(n)
		n.queue_free()

func activate() -> void:
	clearChilds();
	loadstp()


func _on_button_pressed() -> void:
	activate();

func loadVertex(child):
	if (child is CADVertex and vertexOn.button_pressed):
		var v:Node3D = vertexScene.instantiate()
		v.position = (child as CADVertex).get_position() * scalefactor
		childPool.add_child(v)
		
func quaternion_look_at(direction: Vector3, position: Vector3 = Vector3.ZERO, up: Vector3 = Vector3.UP) -> Basis:
	var forward = direction.normalized()
	var right = forward.cross(up).normalized()

	# Wenn forward und up kollinear sind, wähle einen alternativen right-Vektor
	if right.length_squared() < 0.0001:
		if abs(forward.dot(Vector3.UP)) > 0.99: # Forward ist (fast) parallel zu UP
			right = Vector3.FORWARD.cross(forward).normalized()
		else: # Forward ist (fast) parallel zu einer anderen Achse
			right = Vector3.UP.cross(forward).normalized()

	var final_up = right.cross(forward).normalized() # Stelle sicher, dass up orthogonal ist

	var lookat_basis = Basis(right, final_up, -forward).orthonormalized() # Beachte das negative Vorzeichen für forward
	return lookat_basis
		
		
func makeLine(start, end, clr):
	var line_length = start.distance_to(end)
	var direction = (end - start).normalized()
	var transform = Transform3D()
	var basis = quaternion_look_at(direction);
	transform.basis = basis
	transform = transform.scaled_local(Vector3(0.01, 0.01, line_length))
	transform.origin = start + direction * line_length / 2.0
	var v:Node3D = edgeScene.instantiate()
	(v as MeshInstance3D).mesh = (v as MeshInstance3D).mesh.duplicate()
	v.transform = transform
	var material = StandardMaterial3D.new()
	material.albedo_color = clr
	v.mesh.surface_set_material(0, material) # 0 bezieht sich auf die erste
	childPool.add_child(v)
	
func loadEdge(child):
	if (child is CADEdge and edgeOn.button_pressed):
		var edge : CADEdge = child as CADEdge;
		var start = edge.get_cad_start().get_cad_position() * scalefactor
		var end = edge.get_cad_end().get_cad_position() * scalefactor
		makeLine(start,end,Color.WHITE)

func getRandomColor() -> Color:
	var rot = randf()
	var gruen = randf()
	var blau = randf()
	return Color(rot, gruen, blau)
	
func drawWire(wire, clr):
	for x in (wire as CADWire).get_cad_edges():
		var edge : CADEdge = x;
		var start = edge.get_cad_start().get_cad_position() * scalefactor
		var end = edge.get_cad_end().get_cad_position() * scalefactor
		makeLine(start,end,clr)
	
func loadWire(child):
	if (child is CADWire and wireOn.button_pressed):
		var clr = getRandomColor()
		drawWire(child, clr);

func drawFace(child, clr):
	for x in (child as CADFace).get_cad_wires():
		var wire : CADWire = x;
		drawWire(wire,clr)
	

func loadFace(child):
	if (child is CADFace and faceOn.button_pressed):
		var clr = getRandomColor()
		drawFace(child,clr);
		
func drawShell(child, clr):
	for x in (child as CADShell).get_cad_faces():
		var face : CADFace = x;
		drawFace(face,clr)
		
func loadShell(child):
	if (child is CADShell and shellOn.button_pressed):
		var clr = getRandomColor()
		drawShell(child,clr)

func loadSolid(child):
	if (child is CADSolid and solidOn.button_pressed):
		var clr = getRandomColor()
		for x in (child as CADSolid).get_cad_shells():
			var shell : CADShell = x;
			drawShell(shell,clr)

func loadFaceMesh(child):
	if (child is CADFace and faceMeshOn.button_pressed):
		var clr = getRandomColor()
		var mesh = (child as CADFace).get_cad_triangulation(0.1)
		var mesh_instance = MeshInstance3D.new()
		mesh_instance.mesh = mesh
		var material = StandardMaterial3D.new()
		material.albedo_color = Color(1.0, 0.5, 0.2) # Orange
		mesh_instance.material_override = material
		mesh_instance.scale = mesh_instance.scale * scalefactor
		childPool.add_child(mesh_instance)
