#include <armor.h>
inherit SHIELD;

void create()
{
	set_name("������",({"boiler","shield"}) );
	set("long",@LONG
�o�O�@�Ӥ��ÿ��s��������C
LONG
);
	set_weight(2500);		
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
