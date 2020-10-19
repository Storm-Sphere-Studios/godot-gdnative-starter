#pragma once

#include <Godot.hpp>
#include <Node.hpp>

namespace godot
{
	class HelloWorld : public Node
	{
		GODOT_CLASS(HelloWorld, Node)

	public:
		static void _register_methods();
		void _init();
	};
} // namespace godot
