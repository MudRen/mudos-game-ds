#include <armor.h>
inherit ARMOR;

void create()
{
	set_name("��s�@��",({"wood armor","armor"}) );
	set("long",@LONG
�o�O�@��Τ��Y�����@�ҡC
LONG
);
	set_weight(2450);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "wood");
                set("unit", "��");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
