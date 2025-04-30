extends Node

@export var vertexScene : PackedScene;
@export var scalefactor : float = 0.1;

@onready var vertexOn : CheckBox = $VBoxContainer/Vertex
@onready var edgeOn : CheckBox = $VBoxContainer/Edge
@onready var childPool : Node = $ChildPool
@onready var fileLocation : LineEdit = $VBoxContainer/FileLocation

var point_mesh;
var multi_mesh;
var points = []

func traversechilds(child : CADShape, depth):
	var spaces = ""
	for i in range(depth):
		spaces = spaces + " "
	print(spaces + str(child))
	
	loadVertex(child)
	loadEdge(child)
	
	var childs = child.getCADChildren()
	for x in childs:
		traversechilds(x,depth+1)
	pass

func loadstp() -> void:
	var path = fileLocation.text
	var shape = CADShape.loadCADFromFile(path)
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
		
func loadEdge(child):
	if (child is CADEdge and edgeOn.button_pressed):
		#var v:Node3D = vertexScene.instantiate()
		#v.position = (child as CADVertex).get_position() * scalefactor
		#childPool.add_child(v)
		pass
