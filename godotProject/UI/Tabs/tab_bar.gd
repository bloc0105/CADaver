extends TabBar

var is_updating := false

func _ready() -> void:
	Hub.drawings_changed.connect(update_tabs);
	Hub.dirty_changed.connect(update_tabs);
	update_tabs()

func update_tabs():
	is_updating = true
	clear_tabs()
	for draw in Hub.drawings:
		var text := draw.draw_name
		if (draw.dirty):
			text += "(*)"
		add_tab(text)
	current_tab = Hub.drawings.find(Hub.currentDrawing)
	is_updating = false
		
		
func _on_tab_close_pressed(tab: int) -> void:
	Hub.close_drawing.emit(tab)

func _on_tab_changed(tab: int) -> void:
	if (is_updating):
		return
	Hub.currentDrawing = Hub.drawings[tab]
	Hub.current_drawing_changed.emit()
