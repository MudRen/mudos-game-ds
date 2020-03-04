//u/c/chiaa/obj/eq/amber_ring.c
#include <ansi.h>
#include <armor.h>
inherit FINGER;  //手指部分

void create()
{
        set_name(HIY"琥珀"CYN"戒指"NOR,({"amber ring","ring"}) );
        set("long","以珍貴的天然礦石琥珀所做的戒指,有著淡黃色的光澤。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(355); 
                set("unit", "只");       
                set("value",1500);                             
                set("material", "amber");   //琥珀
                set("armor_prop/armor",6);             
                set("armor_prop/int",1);
        }
        
        setup();
}
