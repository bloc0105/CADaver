extends Node

signal fullscreen_mode_changed(bool)

func _ready():
	Hub.root_node = self

func _on_window_content_toggle_fullscreen() -> void:
	if (DisplayServer.window_get_mode() != DisplayServer.WINDOW_MODE_FULLSCREEN): 
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_FULLSCREEN)
		fullscreen_mode_changed.emit(true);
	else:
		DisplayServer.window_set_mode(DisplayServer.WINDOW_MODE_WINDOWED)
		fullscreen_mode_changed.emit(false);
