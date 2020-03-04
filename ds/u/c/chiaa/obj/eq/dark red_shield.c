//u/c/chiaa/obj/eq/dark red_shield.c
#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(RED"深紅之盾"NOR,({"dark red shield ","shield"}) );
        set("long","以天然火紅的鑽石,稍微加工打造,非常堅硬\n");
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(4000);  
                set("limit_str",18);
                set("unit", "個");       
                set("value",5555);                                                     set("material", "diamond");   //鑽石
                set("armor_prop/armor",25);     
                set("armor_prop/shield",16);   
       }
      set("weapon_prop/parry",15);        //加 enable 技能15
          setup();
}
