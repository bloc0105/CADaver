extends PopupMenu

var index_new  = 0;
var index_load = 1;
var index_save = 2;
var index_quit = 3;

func _ready() -> void:
	Hub.file.drawings_changed.connect(on_drawings_changed);
	on_drawings_changed()


func on_drawings_changed() -> void:
	set_item_disabled(index_save,Hub.file.currentDrawing == null)

func _on_index_pressed(index: int) -> void:
	match index:
		index_new:
			new_pressed();
		index_load:
			load_pressed();
		index_save:
			save_pressed();
		index_quit:
			Hub.file.quit_pressed();
			
func new_pressed():
	Hub.file.new_drawing.emit()
	
func load_pressed():
	Hub.file.load_drawing.emit()
	
func save_pressed():
	var index := Hub.file.drawings.find(Hub.file.currentDrawing)
	Hub.file.save_drawing.emit(index)
