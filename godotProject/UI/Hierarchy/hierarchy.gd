class_name Hierarchy extends Control

@onready var tree : Tree = $MarginContainer/VBoxContainer/MarginContainer/Hierarchy

@export var drawing : Drawing;


var root : TreeItem;

func _ready()->void:
	root = tree.create_item()
	
	var child1 = tree.create_item(root)
	child1.set_text(0,"Kartoffel")

func drawing_changed()->void:
	pass
