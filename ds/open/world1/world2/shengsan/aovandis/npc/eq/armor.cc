#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("ĵ�ò���",({"patrol armor","armor"}) );
	set("long",@LONG
�o�O�@��ĵ�åΪ����ҡC
LONG
);
	set_weight(8600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "��");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
