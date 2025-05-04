class_name HubClass extends Node

# Location for all UI Elements. 
# They have to self register.

@warning_ignore("unused_signal")
signal drawings_changed; # void
@warning_ignore("unused_signal")
signal current_drawing_changed; # void
@warning_ignore("unused_signal")
signal load_drawing; # void
@warning_ignore("unused_signal")
signal new_drawing; # void


@warning_ignore("unused_signal")
signal save_drawing; # index int
@warning_ignore("unused_signal")
signal dirty_changed;


@warning_ignore("unused_signal")
signal close_drawing; # index int
var close_drawing_finished := true;
var is_closing := false;

var currentDrawing : Drawing; # selected Tab
var drawings : Array[Drawing]; # All Open Drawings

var drawings_container : Node;
var root_node : Node;



func quit_pressed():
	Hub.is_closing = true
	
	# give a chance to save things
	while(Hub.is_closing and Hub.drawings.size() > 0):
		Hub.close_drawing_finished = false;
		Hub.close_drawing.emit(0)
		while(!Hub.close_drawing_finished):
			await get_tree().create_timer(0.1).timeout
		
	if (Hub.is_closing): # somebody canceled?
		get_tree().quit()
