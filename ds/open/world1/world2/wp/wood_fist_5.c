#include <weapon.h>
inherit FIST;
void create()
{
    set_name("木製指虎",({"wood fist","fist"}));
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
		set("unit", "對");
		set("material", "wood");
		set("long",@LONG
這是一對用木頭製成的指虎。
LONG);
    }
	init_fist(5);
    	setup();
	set("value",300);
	set("volume", 4);
}

