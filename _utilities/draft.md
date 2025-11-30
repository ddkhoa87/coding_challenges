struct Node : std::enable_shared_from_this<Node> {
	...
	this->parent = shared_from_this();
	
polymorphic memory resources

std::cout.setf(std::ios_base::boolalpha);