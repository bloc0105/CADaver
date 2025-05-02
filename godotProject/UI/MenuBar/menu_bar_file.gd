extends PopupMenu

var index_new  = 0;
var index_load = 1;
var index_save = 2;
var index_quit = 3;

func _ready() -> void:
	Hub.open_drawings_changed.connect(on_open_drawings_changed);
	on_open_drawings_changed()

func on_open_drawings_changed() -> void:
	set_item_disabled(index_save,true)

func _on_index_pressed(index: int) -> void:
	print(index);
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
	pass
	
func load_pressed():
	pass
	
func save_pressed():
	pass
	
func quit_pressed():
	get_tree().quit()
