#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("�w���@��",({"hard-wood armor","armor"}) );
	set("long",@LONG
�o�O�@��εw��s�����W�n���@�ҡC
LONG
);
     set_weight(11400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "��");
        }
        set("armor_prop/armor",13);
        setup();
         set("value",1860);
        set("volume", 8);
}

int query_autoload() { return 1; }
