class_name Drawing extends Node

var draw_name : String = "new";
var save_path : String = "";
var dirty     : bool = false; # Save needed?
var shape     : CADShape = null;

func load_from_step_file()->bool: # return success
	shape = CADShape.load_cad_from_file(save_path)
	if (!shape):
		return false;
	dirty = false;
	return true
