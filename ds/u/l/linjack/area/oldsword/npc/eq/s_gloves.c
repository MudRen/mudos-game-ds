#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("��Ȥ�M", ({ "silver gloves","gloves" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o����M�Q������T�c�a, �ӥB���b��Wı�o�Q�����ξA,\n"
                           "�o�ؤ�M�Q���֨�, �i�H����@��Q�b�������C\n");
		set("unit", "��");
		set("value",1500);
		set("material","silver");
	}
	set("armor_prop/armor",4);
	set("armor_prop/parry",25);
	setup();
}
