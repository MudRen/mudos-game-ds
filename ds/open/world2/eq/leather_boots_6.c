#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�־c",({"leather boots","boots"}) );
	set("long",@LONG
�o�O�@���ܱ`�����־c�C
LONG
);
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",880);
	set("armor_prop/armor", 6);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
