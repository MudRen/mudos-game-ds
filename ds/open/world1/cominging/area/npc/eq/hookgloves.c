#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name(HIM"�I�M"HIG"��M"NOR, ({ "hook gloves","gloves","hook" }) );
	set("long","�o�Ƥ�M�O�����E�s���צ欰��K�樫�ҥΪ��˥Ҥ��@�C\n");
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��" );
		set("armor_prop/armor",  5);
	set("material","iron");
		set("limit_dex",14);
		set("value", 120);
	}
	set("wear_msg","$N�ΤO���⨺�j����i$n�C\n");
	set("unequip_msg","$N�ܥΤO�����q$n���ޥX�ӡC\n");
	setup();
}
