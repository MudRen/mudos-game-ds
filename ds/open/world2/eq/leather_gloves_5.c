#include <armor.h>
inherit HANDS;

void create()
{
	set_name("�ϥ֤�M",({"sheep gloves","gloves"}));
	set("long",@LONG
�o�O�@���զ⪺�ϥ֪���M�C
LONG);
	set_weight(620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "leather");
        }
        set("armor_prop/armor",5);
        setup();
        set("value",570);
        set("volume", 2);
}

int query_autoload() { return 1; }
