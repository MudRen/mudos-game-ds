#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("���c", ({ "shoes" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O���u���c���}�W�˳�, �Q���`��²��.\n");
		set("unit", "��");
		set("value",200);
		set("material","cloth");
	}
	set("armor_prop/armor",1);
	setup();
}
