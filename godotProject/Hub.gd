class_name HubClass extends Node

# Location for all UI Elements. 
# They have to self register.

signal drawings_changed; # void
signal current_drawing_changed; # void
signal load_drawing; # void
signal new_drawing; # void


signal save_drawing; # index int
signal dirty_changed;


signal close_drawing; # index int
var close_drawing_finished := true;
var is_closing := false;

var currentDrawing : Drawing; # selected Tab
var drawings : Array[Drawing]; # All Open Drawings

var drawings_container : Node;
var root_node : Node;
