#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�x�y�c",({"basketball boots","boots"}) );
	set("long",@LONG
�o�O�@���ܢע٢ӥX�~���x�y�c�C
LONG
);
	set_weight(3200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
	}
	set("value",1670);
	set("armor_prop/armor", 7);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
