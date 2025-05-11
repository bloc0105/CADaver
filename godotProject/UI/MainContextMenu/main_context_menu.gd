class_name main_context_menu extends PopupMenu

@export var selected : Array[Selectable];

var index_extrude : int = 0


func _on_index_pressed(index: int) -> void:
		match index:
			index_extrude:
				for x in selected:
					var result := CADOperation.extrude(x.get_shape(),Vector3(0,1,0))
					if (result):
						var dlg = SaveFileDialog.new()
						dlg.add_filter("Step File", ["stp","step"])
						dlg.set_save_file_name("Extrusion.step");
						dlg.execute()
						if (!dlg.is_canceled()):
							result.save_cad_to_file(dlg.get_result_path())
