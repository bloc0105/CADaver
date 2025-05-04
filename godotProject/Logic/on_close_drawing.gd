extends Node

var current_drawing : Drawing;

func _ready() -> void:
	Hub.file.close_drawing.connect(on_close_drawing)
	get_tree().set_auto_accept_quit(false)

func _notification(what : int):
	if what == NOTIFICATION_WM_CLOSE_REQUEST:
		Hub.file.quit_pressed();
		
func on_close_drawing(index) -> void:
	if (Hub.file.drawings.size() <= index):
		Hub.file.close_drawing_finished = true
		return
	var drawing := Hub.file.drawings[index]
	current_drawing = drawing

	if (drawing.dirty):
		save_confirmation();
	else:
		close_drawing()
		Hub.file.close_drawing_finished = true
		
func close_drawing()->void:
		Hub.file.drawings.erase(current_drawing)
		reset_current_drawing(current_drawing)
		Hub.file.drawings_changed.emit()
	
func reset_current_drawing(drawing : Drawing) -> void:
	if (drawing == Hub.file.currentDrawing):
		if (Hub.file.drawings.size() > 0):
			Hub.file.currentDrawing = Hub.file.drawings.back();
			Hub.file.current_drawing_changed.emit()
		else:
			Hub.file.currentDrawing = null;
			Hub.file.current_drawing_changed.emit()

func save_confirmation() -> void:
	var dlg := UnsavedChangesDialog.make("Drawing: " + current_drawing.draw_name)
	await dlg.dialog_finished
	if (dlg.yes_pressed):
		Hub.file.save_drawing.emit(Hub.file.drawings.find(current_drawing))
	if (!dlg.cancel_pressed):	
		close_drawing()
	if (dlg.cancel_pressed):
		Hub.file.is_closing = false
	dlg.queue_free()
	Hub.file.close_drawing_finished = true
	
	
