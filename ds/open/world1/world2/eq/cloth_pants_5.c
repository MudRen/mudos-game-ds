#include <armor.h>
inherit PANTS;

void create()
{
	set_name("���u��",({ "cloth short pants","pants" }) );
	set("long",@LONG
�o�O�@��զ⪺���s�u�ǡA��_�ӤQ���z��C
LONG
);
	set_weight(1620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",499);
        set("volume", 3);
}

int query_autoload() { return 1; }
