#include <weapon.h>
inherit AXE;

void create()
{
        set_name("石斧",({"stone axe","axe"}) );
	set_weight(8400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",@LONG
這把斧頭的斧身是由花崗岩磨成，斧柄則是採用抗磨的朹木。
LONG);
		set("material", "stone");
		set("limit_lv",1);
		set("limit_str",1);
		set("limit_int",1);
		set("limit_dex",1);
		set("limit_con",1);
		set("limit_skill",0);
		
	}
	init_axe(18);
	setup();
	set("value",1280);
}

