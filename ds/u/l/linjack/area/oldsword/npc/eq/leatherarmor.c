#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("�n�֥�", ({ "leather armor","armor" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��֥ҳq�`�O���˥Ҫ��x�L�άO�ͽéҬ諸��\n"
                           "����, �S���ܤj�����m�O, �ӥB��e���l�a, ���ܻ��C\n");
		set("unit", "��");
		set("value",1500);
		set("material","leather");
		set("limit_con",10);
	}
	set("armor_prop/dodge",-5);
	set("armor_prop/shield",3);
	set("armor_prop/armor",6);
	setup();
}
