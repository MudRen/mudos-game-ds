#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"龍魂戒"NOR, ({ "dragon ghost ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                 set("long","據說此戒指是用三眛真火所燒製七七四十九天,\n"
                            "才打造而成.\n");
                set("unit", "只");
         set_weight(2500);
         set("value",1900);
         set_weight(600);
         set("material","gem");
set("limit_lv",20); 
}  
       set("armor_prop/armor", 5);
       set("armor_prop/int",1);
       set("armor_prop/con",2);   
       setup();
}

