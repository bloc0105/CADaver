extends Node

var point_mesh;
var multi_mesh;
var points = []

func traversechilds(child : CADShape, depth):
	var spaces = ""
	for i in range(depth):
		spaces = spaces + " "
	print(spaces + str(child))
	
	if (child is CADVertex):
		points.append((child as CADVertex).get_position())
	
	var childs = child.getCADChildren()
	for x in childs:
		traversechilds(x,depth+1)
	pass

func loadstp() -> void:
	var path = "C:/Users/nicol/Downloads/GenericExtruderMount.step"
	var shape = CADShape.loadCADFromFile(path)
	traversechilds(shape,0);
	

func activate() -> void:
	
	# Erstelle ein einfaches Punkt-Mesh (z.B. eine kleine Kugel)
	point_mesh = SphereMesh.new()
	point_mesh.radius = 1

	# Erstelle ein MultiMesh-Objekt
	multi_mesh = MultiMesh.new()
	multi_mesh.mesh = point_mesh

	loadstp()

	# Setze die Anzahl der Instanzen im MultiMesh
	multi_mesh.instance_count = points.size()

	# Setze die Transformation (Position) für jede Instanz
	for i in range(points.size()):
		var transform = Transform3D()
		transform.origin = points[i]
		multi_mesh.set_instance_transform(i, transform)

	# Erstelle einen MeshInstance3D und weise das MultiMesh zu
	var multi_mesh_instance = MultiMeshInstance3D.new()
	multi_mesh_instance.multimesh = multi_mesh
	add_child(multi_mesh_instance)


func _on_button_pressed() -> void:
	activate();
