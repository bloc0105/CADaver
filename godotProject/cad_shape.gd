extends Node


func traversechilds(child : CADShape, depth):
	var spaces = ""
	for i in range(depth):
		spaces = spaces + " "
	print(spaces + str(child))
	var childs = child.getCADChildren()
	for x in childs:
		traversechilds(x,depth+1)
	pass

func _init() -> void:
	var path = "C:/Users/nicol/Downloads/GenericExtruderMount.step"
	var shape = CADShape.new();
	shape.loadCADFromFile(path)
	traversechilds(shape,0);
	pass
