#include <armor.h>
inherit HEAD;
void create()
{
	set_name("�����uŨ",({ "aweat cloth","cloth" }));
	set_weight(950);
        if ( clonep() )
                set_default_object(__FILE__);
        else {       
		set("unit", "��");
		set("long", "�o�O�@��R����������A�C\n");
	set("material","cloth");
		set("value", 100);
		set("armor_prop/armor",3);  
	}
	setup();
}
