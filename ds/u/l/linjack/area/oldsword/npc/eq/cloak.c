#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("錫邊披風", ({ "cloak" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這件袍雖然不算粗糙, 不過看起來就給人一種很普通的感覺.\n");
		set("unit", "件");
		set("value",1000);
		set("material","cloth");
		set("limit_con",10);
		set("limit_dex",10);
	}
	set("armor_prop/armor",5);
	set("armor_prop/shield",1);
	setup();
}
