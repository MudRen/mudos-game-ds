#include <armor.h>
inherit HEAD;

void create()
{
	set_name("�𶢴U",({"hat"}) );
	set("long",@LONG
�o���ťլ۶����𶢴U�{�b�w�g���y��F�C
LONG
);
	set_weight(1200);
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
