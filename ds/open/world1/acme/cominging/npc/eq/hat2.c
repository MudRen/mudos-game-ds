#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name("��F�x�Q�F�U" ,({ "ossifer's hat","hat" }) );
	set_weight(1300);
	set("long","�o�O�@����F�x���ɩҬ�����U�l�C\n");
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","cloth");
		set("unit", "��" );
		set("value", 450);
	}
	set("armor_prop/armor", 2);
	setup();
} 
