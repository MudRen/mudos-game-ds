#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(MAG"月夜"HIW"˙"BLU"戰甲"NOR, ({ "night armor","armor" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
	{
        set("long",@LONG
這件戰甲是夜神˙瀧的專用戰甲。雖然拿在手上感覺很輕，不過絲毫
不影響它的實用性。這是因為它的材質是一種十分特殊的合金，傳說
中這種合金只有諸神能夠使用。
LONG
	);
        set("unit", "件");
        set("material","steel");
        set("value",1);
	set("no_sell",1);
	set("no_drop",1);
        }
          set("armor_prop/con",25);
        set("armor_prop/int",5);
        set("armor_prop/dodge",5);
        set("armor_prop/shield",20);
        set("armor_prop/armor",100);
        setup();
}

int query_autoload() { return 1; }

void init()
{
	if( environment(this_object()) == this_player() )
	this_player()->set_temp("has_light",1);
}
