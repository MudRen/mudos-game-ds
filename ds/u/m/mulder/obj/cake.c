inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
        set_name(HIC "生日蛋糕"NOR, ({ "birthday cake","cake" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是"HIC"小"HIG"喇"HIY"叭"NOR"的生日蛋糕，因為今天是他的生日\n");
                set("unit", "個");
	    set("no_sac",1);
	    set("no_sell",1);	
	    set("value", 1000000);       
                set("heal_mp",100);
	    set("heal_hp", 100);
	    set("heal_ap", 100);
        	    set("food_remaining", 50);
       }
}