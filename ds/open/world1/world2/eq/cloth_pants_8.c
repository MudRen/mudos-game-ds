#include <armor.h>
inherit PANTS;

void create()
{
	set_name("��˿�",({ "business pants","pants" }) );
	set("long",@LONG
�o�O�@�����P���¦��˿ǡC
LONG
);
	set_weight(1820);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",8);
        setup();
        set("value",850);
        set("volume", 4);
}

int query_autoload() { return 1; }
