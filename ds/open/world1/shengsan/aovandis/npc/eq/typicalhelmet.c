
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("��Y��",({"typical helmet","helm","typical"}) );
	set("long","�o�O���Z�}���u�éҬ諸�Y���C\n");
	set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","steel");
		set("unit", "��");
		set("value",3400);
        	set("armor_prop/armor", 2);
	}
	setup();
}
