#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("����" ,({ "helmet","helmet" }) );
	set("long","�o�O�@���x�L�Ҭ�����Y���A�Y���W�Y�٫��U�F�@�j������Ž�u\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
set("volume",3);
       set_weight(5000);
        set("material","iron");
		set("unit", "��" );
		set("value",800);
	}
	set("armor_prop/armor", 8);
	setup();
} 
