#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�զ⥬�c",({"white cloth boots","boots"}) );
	set("long",@LONG
�o�O�@���զ⪺���c�C
LONG
);
	set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
	}
	set("value",430);
	set("armor_prop/armor", 5);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
