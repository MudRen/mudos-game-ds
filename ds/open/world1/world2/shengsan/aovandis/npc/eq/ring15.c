#include <armor.h>
inherit FINGER;

void create()
{
	set_name("�ߤl�٫�",({"rabbit ring","ring"}) );
	set("long",@LONG
�ѻɥ��y���٤l�A�٭����@�Өߤl���ϮסC
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "copper");
		set("unit", "�T");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
