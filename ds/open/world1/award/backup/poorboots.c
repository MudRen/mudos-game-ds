#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("踏水鞋", ({ "water boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","這雙鞋子很輕, 穿起來會有種飄飄然的感覺。\n");
		set("unit", "雙");
		set("material", "cloth");
	set("needaward",9);
	set("value",1);
	}
	set("armor_prop/dex",3);
	set("armor_prop/dodge",30);
	set("armor_prop/armor",6);
	setup();
}

int query_autoload() { return 1; }
