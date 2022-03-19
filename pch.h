#pragma once

//typedef int (*EntryFunc)();
int perfect_forward();
int move_constructor();
int no_except();
int size_struct_member();
int convert_implicit();
int convert_explicit();
int initializer_list();
int trivial_pod();
int standard_layout();
int ispod();
int union_like_class();
int using_typedef();
int typeid_hash_code();

//EntryFunc = perfect_forward;

/* array with three functions */
int (*EntryFunc[])() = {
	typeid_hash_code,
	using_typedef,
	union_like_class,
	ispod,
	standard_layout,
	trivial_pod,
	initializer_list,
	convert_explicit,
	convert_implicit,
	perfect_forward, 
	move_constructor, 
	no_except, 
	size_struct_member 
};



