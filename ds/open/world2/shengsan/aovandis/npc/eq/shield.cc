#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("���ɬ޵P",({"riot shield","shield"}) );
	set("long",@LONG
�o�O���Z�}���u�éҸ˳ƪ����ɬ޵P�C
LONG
);
	set_weight(6600);		
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
	}
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
