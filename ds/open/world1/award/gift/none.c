#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"�Ŭ��]"NOR, ({ "red envelope","bag","envelope" }) );
	set_weight(50);
	set_max_encumbrance(25000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","�o�O�ʨS�˪F�誺���]�C\n");
		set("value", 10);
	}
	setup();
}
