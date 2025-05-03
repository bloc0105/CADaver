extends Node

var current_drawing : Drawing;

func _ready() -> void:
	Hub.close_drawing.connect(on_close_drawing)

func on_close_drawing(index) -> void:
	if (Hub.drawings.size() <= index):
		return
	var drawing := Hub.drawings[index]
	current_drawing = drawing

	if (drawing.dirty):
		save_confirmation();
	else:
		close_drawing()
		
func close_drawing()->void:
		Hub.drawings.erase(current_drawing)
		reset_current_drawing(current_drawing)
		Hub.drawings_changed.emit()
	
func reset_current_drawing(drawing : Drawing) -> void:
	if (drawing == Hub.currentDrawing):
		if (Hub.drawings.size() > 0):
			Hub.currentDrawing = Hub.drawings.back();
			Hub.current_drawing_changed.emit()
		else:
			Hub.currentDrawing = null;
			Hub.current_drawing_changed.emit()

func save_confirmation() -> void:
	var dlg := UnsavedChangesDialog.make("Drawing: " + current_drawing.draw_name)
	dlg.yes_pressed.connect(confirmation_confirmed)
	dlg.no_pressed.connect(confirmation_declined)
	dlg.cancel_pressed.connect(confirmation_canceled)

func confirmation_canceled()->void:
	pass
	
func confirmation_confirmed()->void:
	print("Saved")
	close_drawing()
	
func confirmation_declined()->void:
	print("Not saved");
	close_drawing()
