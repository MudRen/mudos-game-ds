#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIC"小喇叭專用鎧"NOR ,({ "steel armor","steel","armor" }) );
        set("long","這是用純鋼所煉成的鎧甲。\n");
	set_weight(12000);
        if ( clonep() )
	set_default_object(__FILE__);
        else {
              set("material", "armor");
	set_weight(3000);
	set("value", 4000);
	set("no_sac",1);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
	set("limit_str",15);
	set("unit", "件" );
        set("material","steel");
	set("armor_prop/dodge", 20);
	set("armor_prop/parry",20);
        set("armor_prop/armor", 200);
        set("armor_prop/shield", 50);
        }
        setup();

}	
int query_autoload() { return 1; }

