#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�j�ƥ־c",({"adv-leather boots","boots"}) );
	set("long",@LONG
�o�O�@���g�L�j�Ƴ]�p����T�־c�C
LONG
);
	set_weight(5200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",1140);
	set("armor_prop/armor", 8);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
