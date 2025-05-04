extends PopupMenu

var index_fullscreen  = 0;
var index_load = 1;
var index_save = 2;
var index_quit = 3;

func _ready():
	add_submenu_node_item("Frames",$Frames)

func _on_index_pressed(index: int) -> void:
	match index:
		index_fullscreen:
			toggle_fullscreen()	

func toggle_fullscreen() -> void:		
	toggle_item_checked(index_fullscreen)
	if (is_item_checked(index_fullscreen)):
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
	else:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
