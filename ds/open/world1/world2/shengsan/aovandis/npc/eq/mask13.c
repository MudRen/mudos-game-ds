#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("�f�n", ({ "mask" }) );
	set("long",@LONG
�o�O�@�ƥզ⪺�f�n�C
LONG
);
	set_weight(1300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
