
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("ĵ���Y��",({"patrol helmet","helmet","patrol"}) );
	set("long","�o�O���Z�}��ĵ�ñM�Ϊ��Y���C\n");
	set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",2300);
	}
	setup();
}

int query_autoload() { return 1; }
