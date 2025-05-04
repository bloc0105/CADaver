class_name ApplicationMenuBar extends PanelContainer

@export var window : WindowContainer

@onready var view : ViewMenu = $MenuBar/View

func _on_window_content_fullscreen_mode_set(on: bool) -> void:
	view.set_fullscreen(on)
