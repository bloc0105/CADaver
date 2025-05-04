class_name file_config extends Node

@warning_ignore("unused_signal")
signal load_drawing; # void
@warning_ignore("unused_signal")
signal new_drawing; # void
@warning_ignore("unused_signal")
signal close_drawing; # index int
@warning_ignore("unused_signal")
signal save_drawing; # index int
@warning_ignore("unused_signal")
signal dirty_changed;
@warning_ignore("unused_signal")
signal drawings_changed; # void
@warning_ignore("unused_signal")
signal current_drawing_changed; # void

var close_drawing_finished := true;
var is_closing := false;

var currentDrawing : Drawing; # selected Tab
var drawings : Array[Drawing]; # All Open Drawings


func quit_pressed():
	if (Hub.file.is_closing):
		return
	Hub.file.is_closing = true
	
	while(Hub.file.is_closing and Hub.file.drawings.size() > 0):
		Hub.file.close_drawing_finished = false;
		Hub.file.close_drawing.emit(0)
		while(!Hub.file.close_drawing_finished):
			await Hub.root_node.get_tree().create_timer(0.1).timeout
		
	if (Hub.file.is_closing): # somebody canceled?
		Hub.root_node.get_tree().quit()
