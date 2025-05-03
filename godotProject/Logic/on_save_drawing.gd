extends Node

@export var drawingScene : PackedScene

var currentDrawing : Drawing;

func _ready() -> void:
	Hub.save_drawing.connect(on_save_drawing)

func on_save_drawing(index) -> void:
	var d := Hub.drawings[index]
	if (!d.dirty):
		return
	currentDrawing = d
	invokeSaveFileDialog()


func invokeSaveFileDialog():
	var file_dialog = FileDialog.new()
	file_dialog.file_mode = FileDialog.FILE_MODE_SAVE_FILE
	file_dialog.filters = PackedStringArray(["*.proj ; Projekt", "*.stp ; STEP File", "*.stl ; STL File"])
	file_dialog.confirmed.connect(_on_file_dialog_confirmed)
	file_dialog.canceled.connect(_on_file_dialog_canceled)
	file_dialog.access = FileDialog.ACCESS_FILESYSTEM
	add_child(file_dialog)
	file_dialog.popup_centered()

func _on_file_dialog_confirmed(path_to_save):
	print("User wants to save to:", path_to_save)

	if is_instance_valid(get_node("FileDialog")):
		get_node("FileDialog").queue_free()
	
	currentDrawing.dirty = false
	Hub.dirty_changed.emit()


func _on_file_dialog_canceled():
	print("Save file dialog canceled.")
	if is_instance_valid(get_node("FileDialog")):
		get_node("FileDialog").queue_free()
