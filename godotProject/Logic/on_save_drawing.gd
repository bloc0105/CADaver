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
	var dlg = SaveFileDialog.new()
	dlg.add_filter("Step File", ["stp","step"])
	dlg.set_save_file_name(currentDrawing.name + ".step");
	dlg.execute()
	
	if (!dlg.is_canceled()):
		print("Save");
		currentDrawing.dirty = false
		Hub.dirty_changed.emit()
