#pragma once

//typedef int (*EntryFunc)();
int perfect_forward();
int move_constructor();
int no_except();
int size_struct_member();
int convert_implicit();
int convert_explicit();
int initializer_list();

//EntryFunc = perfect_forward;

/* array with three functions */
int (*EntryFunc[])() = { 
	initializer_list,
	convert_explicit,
	convert_implicit,
	perfect_forward, 
	move_constructor, 
	no_except, 
	size_struct_member 
};



