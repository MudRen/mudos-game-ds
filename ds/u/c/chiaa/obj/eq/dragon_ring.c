//u/c/chiaa/obj/eq/dragon_ring.c
#include <ansi.h>
#include <armor.h>
inherit FINGER;  //手指部分

void create()
{
        set_name(HIC"龍"HIG"元"HIW"戒"NOR,({"dragon ring","ring"}) );
        set("long","一只銀白色澤的指環,上面還刻了一條龍。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(300); 
                set("unit", "只");       
                set("value",1200);                             
                set("material", "silver");   
                set("armor_prop/armor",10);       
                set("armor_prop/str",3);
                set("armor_prop/int",2);
        }
        
        setup();
}
