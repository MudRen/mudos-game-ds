#include <ansi2.h> 
#include <armor.h>
inherit SHIELD;
void create()
{
        set_name(HIW"ＤＳ盾牌"NOR,({"ds shield","shield"}));
        set_weight(600);            
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("unit", "對");
        set("material","steel");
        set("long",@LONG 
為低等級所打造的盾牌。
LONG
        ); 
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("value",0);
        set("volume",0);
   set("armor_prop/armor",5);  
        }
        setup();
}

