//u/c/chiaa/obj/eq/hon len_belt.c
#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(HIR"紅凌"HIB"腰帶"NOR,({"hon len belt","belt"}) );
        set("long","一條摸起來相當柔軟,讓你感覺很舒服的腰帶。\n");

        if (clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200);
                set("unit","條");        
                set("material","fur");
                set("armor_prop/armor",6);
                set("value", 200);
        }
        setup();
}
