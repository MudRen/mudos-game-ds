#include <armor.h>
inherit PANTS;

void create()
{
	set_name("�j�������J��",({ "big-train jeans","jeans" }) );
	set("long",@LONG
�o�O�@��j�����P���`�Ŧ���J���ǡC
LONG
);
	set_weight(2620);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("armor_prop/armor",9);
        setup();
        set("value",1249);
        set("volume", 4);
}

int query_autoload() { return 1; }
