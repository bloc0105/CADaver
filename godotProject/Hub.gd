class_name HubClass extends Node

# Location for all UI Elements. 
# They have to self register.

signal drawings_changed; # void
signal current_drawing_changed; # void
signal load_drawing; # void
signal new_drawing; # void
signal close_drawing; # index int
signal save_drawing; # index int
signal dirty_changed;

var is_closing = false;


var currentDrawing : Drawing; # selected Tab
var drawings : Array[Drawing]; # All Open Drawings

var drawings_container : Node;
var root_node : Node;
