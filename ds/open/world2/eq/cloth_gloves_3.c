#include <armor.h>
inherit HANDS;

void create()
{
	set_name("�ե���M",({"white cloth gloves","gloves"}));
	set("long",@LONG
�o�O�@���զ⪺����M�C
LONG);
	set_weight(420);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "cloth");
        }
        set("armor_prop/armor",3);
        setup();
        set("value",270);
        set("volume", 2);
}

int query_autoload() { return 1; }
