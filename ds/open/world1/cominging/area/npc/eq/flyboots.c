#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name(HIM"���B"HIG"�u"NOR ,({ "hight boots" , "boots" , "hight" }) );
	set("long","�o�O�e�����M�Ϊ��c�l�A�ǻ���W�o���c�l��A�๳�ߨ����@�몺���C\n");
	set_weight(3000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit"  ,"��");
		set("value" , 220);
		set("armor_prop/dex",   1);
	set("material","cloth");
		set("volume",2);
		set("armor_prop/armor", 2);
	}
	set("wear_msg","$N��W�F�e������$n�C\n");
    set("unequip_msg","$N��U�F$n�C\n");
	setup();
}
