#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("羊皮鞭",({"sheep-skin whip","whip"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "支");
		set("material", "skin");
		set("long",@LONG
這是一支以羊皮製成的皮鞭。
LONG);
    }
	init_whip(10);
    	setup();
	set("value",800);
	set("volume", 6);
}

