#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("�ֹu", ({ "skin boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O���򤤤H���䴶�M���˳Ƥ��@, �����L�_.\n");
		set("unit", "��");
		set("value",500);
		set("material","fur");
	}
	set("armor_prop/armor",3);
	setup();
}
