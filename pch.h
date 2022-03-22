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
int trait_return_type();
int for_foreach();
int class_enum();
int smart_pointer();
int va_sum();
int var_template();
int var_func();
int atomic_op();
int memory_model();
int exit_do();
//EntryFunc = perfect_forward;

/* array with three functions */
int (*EntryFunc[])() = {
	exit_do,
	memory_model,
	atomic_op,
	var_func,
	var_template,
	va_sum,
	smart_pointer,
	class_enum,
	for_foreach,
	trait_return_type,
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



