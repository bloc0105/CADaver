extends Node


func _ready() -> void:
	Hub.close_drawing.connect(on_close_drawing)

func on_close_drawing(index) -> void:
	if (Hub.drawings.size() <= index):
		return
	var drawing := Hub.drawings[index]

	Hub.drawings.erase(drawing)
	reset_current_drawing(drawing)
	Hub.drawings_changed.emit()
	
func reset_current_drawing(drawing : Drawing) -> void:
	if (drawing == Hub.currentDrawing):
		if (Hub.drawings.size() > 0):
			Hub.currentDrawing = Hub.drawings.back();
			Hub.current_drawing_changed.emit()
		else:
			Hub.currentDrawing = null;
			Hub.current_drawing_changed.emit()
	
