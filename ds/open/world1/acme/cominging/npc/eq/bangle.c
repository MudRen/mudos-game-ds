#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("黑玉手鐲" ,({ "black jade bangle","bangle" }) );
	set_weight(800);
	set("long","這個黑玉手鐲手工精細，尤其是由黑玉所造，實為一項珍寶。\n");
	if ( clonep() )
	      set_default_object(__FILE__);
	else {
         set("material","jade");
		set("unit", "個" );
          set("value",400);
	}
	set("armor_prop/armor", 1);
	set("armor_prop/shield", 1);
	set("armor_prop/hit",3);
	setup();
} 
