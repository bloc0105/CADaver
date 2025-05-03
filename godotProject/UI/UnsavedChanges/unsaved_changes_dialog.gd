class_name UnsavedChangesDialog extends Control

@export var hint : String  = "Drawing: new";

@onready var hint_label = $PanelContainer/MarginContainer/VBoxContainer/Hint

signal yes_pressed;
signal no_pressed;
signal cancel_pressed;

static func make(hint : String) -> UnsavedChangesDialog:
	var dlg := preload("res://UI/UnsavedChanges/UnsavedChangesDialog.tscn").instantiate()
	dlg.hint = hint;
	Hub.root_node.add_child(dlg)
	return dlg;

func _ready() -> void:
	hint_label.text = hint

func _on_yes_pressed() -> void:
	yes_pressed.emit()
	queue_free()

func _on_no_pressed() -> void:
	no_pressed.emit()
	queue_free()

func _on_cancel_pressed() -> void:
	cancel_pressed.emit()
	queue_free()
