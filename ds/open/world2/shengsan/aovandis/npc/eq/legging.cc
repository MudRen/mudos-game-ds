
#include <armor.h>
inherit LEGGING;

void create()
{
	set_name("��j�L",({"typical leggings","leggings"}) );
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
