#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
	set_name("�D�y",({"bath towel","towel"}) );
	set("long",@LONG
�o�O�@���Ŧ⪺�j�D�y�C
LONG
);
	set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
        }
        set("auto_set",2);
        setup();
}

// int query_autoload() { return 1; }
