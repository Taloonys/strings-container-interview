# Key tasks:
* Fill containers
* Fill containers randomly (string_number < container_number)
* Return container id that contain concrete string

# Structure
* `Container` -> holds strings in `set`s
* `ContainerManager` -> is an interface/manager for containers-hashmap
* `TerminalHandler` -> provides terminal interaction with user
* `ICommandUnit & Terminal<Task>` -> just a simple fabric of terminal options (find, fill, clear and etc.)
