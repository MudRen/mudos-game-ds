
#include <armor.h>
inherit WRISTS;

void create()
{
	set_name("��@�u",({"typical wrists","wrists"}) );
	set("long",@LONG
�o�O���Z�}���u�éҸ˳ƪ��@�u�C
LONG
);
	set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("material", "steel");
	}
	set("auto_set",2);
	setup();
}

//int query_autoload() { return 1; }
