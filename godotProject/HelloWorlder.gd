extends Label


func _init() -> void:
	var obj:HelloWorldGD = HelloWorldGD.new();
	text = obj.getHelloWorldMessage()
	pass
