#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�B�ʾc",({"sport boots","boots"}) );
	set("long",@LONG
�o�O�@��Made in Taiwan���B�ʾc�C
LONG
);
	set_weight(2300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
	}
	set("value",770);
	set("armor_prop/armor", 6);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
