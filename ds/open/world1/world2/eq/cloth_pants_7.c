#include <armor.h>
inherit PANTS;

void create()
{
	set_name("�¥�����",({ "cloth pants","pants" }) );
	set("long",@LONG
�o�O�@��Ŧ⪺���s���ǡC
LONG
);
	set_weight(2220);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",7);
        setup();
        set("value",849);
        set("volume", 4);
}

int query_autoload() { return 1; }
