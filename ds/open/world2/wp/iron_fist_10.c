#include <weapon.h>
inherit FIST;
void create()
{
    set_name("鐵指虎",({"iron fist","fist"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "對");
		set("material", "iron");
		set("long",@LONG
這是一對用熟鐵打造製成的指虎。
LONG);
    }
	init_fist(10);
    	setup();
	set("value",800);
	set("volume", 6);
}

