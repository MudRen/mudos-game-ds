#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("�|���K�c",({"fc iron boots","boots"}) );
	set("long",@LONG
�o�O�@���|�겣�~�s�y���K�־c�A�K�s���c���۷�e�����áC
LONG
);
	set_weight(5300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "��");
	}
	set("value",1440);
	set("armor_prop/armor", 9);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
