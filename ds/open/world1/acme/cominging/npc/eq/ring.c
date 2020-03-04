#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
	set_name(HIC"無極之戒"NOR,({ "wu ji ring","ring" }) );
	set("long","這枚戒指很特別，是由藍水晶雕刻而成，\n"
		   "卻雕成一火炎的形狀；一把藍火炎，故有\n"
		   "人稱之為『藍之炎』。\n"
	   );
    set_weight(1500);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
        set("material","gem");
		set("unit", "件" );
		set("value",1500);
		set("armor_prop/armor", 3);
		set("armor_prop/shield",3);
		set("armor_prop/dodge",3);
	}
	setup();
}
