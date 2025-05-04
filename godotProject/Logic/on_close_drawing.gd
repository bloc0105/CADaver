extends Node

var current_drawing : Drawing;

func _ready() -> void:
	Hub.close_drawing.connect(on_close_drawing)
	get_tree().set_auto_accept_quit(false)

func _notification(what : int):
	if what == NOTIFICATION_WM_CLOSE_REQUEST:
		Hub.quit_pressed();
		
func on_close_drawing(index) -> void:
	if (Hub.drawings.size() <= index):
		Hub.close_drawing_finished = true
		return
	var drawing := Hub.drawings[index]
	current_drawing = drawing

	if (drawing.dirty):
		save_confirmation();
	else:
		close_drawing()
		Hub.close_drawing_finished = true
		
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
	await dlg.dialog_finished
	if (dlg.yes_pressed):
		Hub.save_drawing.emit(Hub.drawings.find(current_drawing))
	if (!dlg.cancel_pressed):	
		close_drawing()
	if (dlg.cancel_pressed):
		Hub.is_closing = false
	dlg.queue_free()
	Hub.close_drawing_finished = true
	
	
