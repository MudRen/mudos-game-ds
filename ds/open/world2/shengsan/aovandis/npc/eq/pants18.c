
#include <armor.h>
inherit PANTS;

void create()
{
	set_name("�B�ʵu��",({ "short pants","pants" }) );
	set("long",@LONG
�o�O�@��¦⪺NIKE�B�ʿǡA�ܾA�X��ӥ��x�y�C
LONG
);
	set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("auto_set",2);
        setup();
}

//int query_autoload() { return 1; }
