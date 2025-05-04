extends TabBar

var is_updating := false

func _ready() -> void:
	Hub.file.drawings_changed.connect(update_tabs);
	Hub.file.dirty_changed.connect(update_tabs);
	update_tabs()

func update_tabs():
	is_updating = true
	clear_tabs()
	for cdraw in Hub.file.drawings:
		var text := cdraw.draw_name
		if (cdraw.dirty):
			text += "(*)"
		add_tab(text)
	current_tab = Hub.file.drawings.find(Hub.file.currentDrawing)
	is_updating = false
		
		
func _on_tab_close_pressed(tab: int) -> void:
	Hub.file.close_drawing.emit(tab)

func _on_tab_changed(tab: int) -> void:
	if (is_updating):
		return
	Hub.file.currentDrawing = Hub.file.drawings[tab]
	Hub.file.current_drawing_changed.emit()
