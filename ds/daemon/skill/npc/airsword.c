// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("�Ů�C", ({ "air sword", "sword" }));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��Ů�C�O�Q�ή�l�Ҿ��X�Ӫ��C�A�ѩ󤣬O����A�ҥH�u������@�q�u�ɶ��C\n");
		set("no_drop", 1);
		set("no_sac", 1);
		set("no_give", 1);
		set("no_get", 1);
		set("no_put", 1);
		set("value", 0);
		set("material", "steel");
	}
	init_sword(20);
// These properties are optional, if you don't set them, it will use the
// default values.


// The setup() is required.

	setup();
}

void init()
{
        object room;
        room = environment(this_object());

        if( !room ) return;
        if( !objectp(room) ) return;
        if( room->is_room() ) destruct(this_object());
}
