#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("����", ({ "mask" }) );
	set("long",@LONG
�o�O�@�ƭ���C
LONG
);
	set_weight(2100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "silk");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
