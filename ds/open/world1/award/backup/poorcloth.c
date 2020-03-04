#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name("特製皮甲", ({ "special leather armor","armor" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件皮甲穿在身上, 活動靈活不受阻礙, 算是縫製得\n"
                           "很好的一件皮甲, 但是這皮甲是暗藍色的, 看來頗怪異。\n");
	set("value",1);
		set("unit", "件");
		set("material", "leather");
		set("needaward",15);
	}
	set("armor_prop/parry",12);
	set("armor_prop/armor",20);
	set("armor_prop/shield",15);
	set("armor_prop/bio",-1);
	set("armor_prop/wit",1);
	setup();
}

int query_autoload() { return 1; }
