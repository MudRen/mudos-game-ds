#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�ֹu",({"boots"}));
	set("long","�o�Oĵ��`�Ϊ��ֹu�C\n");
     set_weight(1500);
	if (clonep() )
		set_default_object(__FILE__);
	else {
	set("unit","��");
        set("value",500);           
	set("material","boots");
	set("armor_prop/armor",4);
	}
	setup();
}

