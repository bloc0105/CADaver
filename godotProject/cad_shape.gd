extends CADShape


func _init() -> void:
	var path = "C:/Users/nicol/Downloads/GenericExtruderMount.step"
	print(loadFromFile(path))
	pass
