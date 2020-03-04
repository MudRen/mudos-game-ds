// dumpling.c

inherit ITEM;
#include <ansi.h>

inherit F_PILL;

void create()
{
        set_name(HIB"藍色小藥丸"NOR, ({ "blue pill","pill" }) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一顆藍色的小藥丸，似乎能增強某種能力。\n");
                set("unit", "顆");
                set("value", 300);       
                set("heal_ap",30);      
                set("heal_body",10);    
                set("heal_head",10);    
                set("eat_msg","$N吃了一顆$n以後, 有一股想要發洩的慾望。");
                set("eff_msg","你覺得內力增強了不少。");
        }
        setup();
}
