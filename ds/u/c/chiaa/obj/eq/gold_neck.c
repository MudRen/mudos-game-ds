//u/c/chiaa/obj/eq/gold_neck.c

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
        set_name(HIY"金項鍊"NOR,({"gold_neck","neck"}) );
        set("long","一條純金打造而成的項鍊，看起來價值不斐。\n");    
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "條");
                set_weight(10);        
                set("value",5000);          
                set("armor_prop/armor",3);  //防禦3   
                set("material", "gold");    //材質 金   
        }
        
       setup();
}
