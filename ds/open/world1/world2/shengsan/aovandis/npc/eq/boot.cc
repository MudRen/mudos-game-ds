
#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("��Ծc",({"typical war boot","boot"}) );
	set("long",@LONG
�o�O���Z�}���u�éҸ˳ƪ��Ծc�C
LONG
);
	set_weight(6000);
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
