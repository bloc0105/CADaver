extends PopupMenu

var index_new  = 0;
var index_load = 1;
var index_save = 2;
var index_quit = 3;

func _ready() -> void:
	Hub.drawings_changed.connect(on_drawings_changed);
	on_drawings_changed()

func on_drawings_changed() -> void:
	set_item_disabled(index_save,Hub.currentDrawing == null)

func _on_index_pressed(index: int) -> void:
	match index:
		index_new:
			new_pressed();
		index_load:
			load_pressed();
		index_save:
			save_pressed();
		index_quit:
			quit_pressed();
			
func new_pressed():
	Hub.new_drawing.emit()
	
func load_pressed():
	Hub.load_drawing.emit()
	
func save_pressed():
	var index := Hub.drawings.find(Hub.currentDrawing)
	Hub.save_drawing.emit(index)
	
func quit_pressed():
	Hub.is_closing = true
	
	# give a chance to save things
	while(Hub.is_closing and Hub.drawings.size() > 0):
		Hub.close_drawing_finished = false;
		Hub.close_drawing.emit(0)
		while(!Hub.close_drawing_finished):
			await get_tree().create_timer(0.1).timeout
		
	if (Hub.is_closing): # somebody canceled?
		get_tree().quit()
