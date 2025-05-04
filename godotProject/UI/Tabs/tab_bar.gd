class_name OpenDrawingsTabs extends TabBar

@export var window : WindowContainer

var is_updating := false

signal drawing_changed(index); # int index

func _ready() -> void:
	Hub.file.drawings_changed.connect(update_tabs);
	Hub.file.dirty_changed.connect(update_tabs);
	Hub.show_tabs_changed.connect(show_tabs_changed);
	update_tabs()

func update_tabs():
	is_updating = true
	clear_tabs()
	for cdraw in Hub.file.drawings:
		var text := cdraw.draw_name
		if (cdraw.dirty):
			text += "(*)"
		add_tab(text)
	current_tab = Hub.file.drawings.find(window.scene.drawing)
	is_updating = false
		
func _on_tab_close_pressed(tab: int) -> void:
	Hub.file.close_drawing.emit(tab)

func _on_tab_changed(tab: int) -> void:
	if (is_updating):
		return
	drawing_changed.emit(tab)

func show_tabs_changed()->void:
	visible = Hub.show_tabs
