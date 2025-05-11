class_name main_context_menu extends PopupMenu

@export var selected : Array[Selectable];

var index_extrude : int = 0


func _on_index_pressed(index: int) -> void:
		match index:
			index_extrude:
				for x in selected:
					CADOperation.extrude(x.get_shape(),Vector3(1,0,0))
