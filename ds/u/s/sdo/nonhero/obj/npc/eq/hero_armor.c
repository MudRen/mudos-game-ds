#include <ansi2.h>
#include <armor.h>
inherit ARMOR;
void create()
{
        set_name(HIC"英雄戰甲"NOR,({"hero armor","armor"}));
        set_weight(25000);            
        if( clonep() )
   	        set_default_object(__FILE__);
        else 
	{
     	set("unit", "件");
        set("material","steel");
       	set("long",@LONG 
這件戰甲是由精鋼所打造而成，雖然經歷不少戰鬥，上面的刮痕卻不
多，由此可見此戰甲的材質多麼堅硬。
LONG
	);
  	set("value",4000);
        set("volume",5);
	set("armor_prop/con",2);
        set("armor_prop/armor",30);  
        }
        setup();
}