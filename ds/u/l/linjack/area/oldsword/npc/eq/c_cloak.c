#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("�ܶ�����", ({ "cloud cloak","cloak" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���A�S�s������M�_�s��k, �����ܦ����ӱj��\n"
                           "�������m�O�窫.\n");
		set("unit", "��");
		set("value",10000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",10);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",6);
	set("armor_prop/shield",2);
	setup();
}
