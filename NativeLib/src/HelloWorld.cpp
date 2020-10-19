#include "HelloWorld.h"

using namespace godot;

void HelloWorld::_register_methods()
{
}

void HelloWorld::_init()
{
	Godot::print("Hello World!");
}