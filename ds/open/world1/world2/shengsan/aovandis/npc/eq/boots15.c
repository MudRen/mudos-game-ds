
#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("���c",({"boots"}) );
	set("long",@LONG
�o�O�@���ܱ`�������c�C
LONG
);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "iron");
		set("unit", "��");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
