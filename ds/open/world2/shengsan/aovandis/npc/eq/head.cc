#include <armor.h>
inherit HEAD;

void create()
{
	set_name("��Y��",({"typical helmet","helmet"}) );
	set("long",@LONG
�o�O���Z�}���u�éҬ諸�Y���C
LONG
);
	set_weight(3300);
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
