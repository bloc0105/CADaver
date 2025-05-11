class_name path_util extends Node

static func get_file_name_from_path(path: String) -> String:
	if path.is_empty():
		return ""
	var last_slash_index = path.rfind("/")
	if last_slash_index != -1:
		if last_slash_index == path.length() - 1:
			return ""
		return path.substr(last_slash_index + 1)
	else:
		return path

static func get_file_name_without_extension(path: String) -> String:
	var file_name_with_ext = get_file_name_from_path(path)
	if not file_name_with_ext.is_empty():
		var dot_index = file_name_with_ext.rfind(".")
		if dot_index != -1:
			return file_name_with_ext.substr(0, dot_index)
		else:
			return file_name_with_ext
	return ""

static func get_path_without_filename(path: String) -> String:
	if path.is_empty():
		return ""
	var last_slash_index = path.rfind("/")
	if last_slash_index != -1:
		if last_slash_index == path.length() - 1:
			return ""
		return path.substr(0,last_slash_index + 1)
	else:
		return path

static func get_extension(path : String)->String:
	var last_dot_index = path.rfind(".")
	if last_dot_index != -1 and last_dot_index < path.length() - 1:
		return path.substr(last_dot_index)
	else:
		return ""
