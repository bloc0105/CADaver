extends Node

@export var vertexScene : PackedScene;
@export var scalefactor : float = 0.1;

var point_mesh;
var multi_mesh;
var points = []

func traversechilds(child : CADShape, depth):
	var spaces = ""
	for i in range(depth):
		spaces = spaces + " "
	print(spaces + str(child))
	
	if (child is CADVertex):
		var v:Node3D = vertexScene.instantiate()
		v.position = (child as CADVertex).get_position() * scalefactor
		add_child(v)
	
	var childs = child.getCADChildren()
	for x in childs:
		traversechilds(x,depth+1)
	pass

func loadstp() -> void:
	var path = "C:/Users/nicol/Downloads/GenericExtruderMount.step"
	var shape = CADShape.loadCADFromFile(path)
	traversechilds(shape,0);
	
	
func clearChilds() -> void:
	for n in self.get_children():
		self.remove_child(n)
		n.queue_free()

func activate() -> void:
	clearChilds();
	loadstp()


func _on_button_pressed() -> void:
	activate();
