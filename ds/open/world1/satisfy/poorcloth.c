#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name("�w�֦�", ({ "hardend cloth","cloth" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�@�󦳤@�w���@�O���֦�C\n");
		set("unit", "��");
		set("material", "cloth");
//		set("no_drop",1);
		set("no_sac",1);
		set("value",15000);
		set("armor_prop/parry",2);
		set("armor_prop/armor",4);
	}
	setup();
}

int query_autoload() { return 1; }