#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("九轉回命丹", ({ "nine pill","pill" }));
        set("long",
"一顆混黑色的丹丸，隱隱帶有紫光，看不出其效用如用。\n"
        );
        set_weight(200);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("unit", "顆");
        set("value", 400);
        set("heal_hp",60+random(11));
        set("food_remaining", 20);
        set("eat_msg","$N吃下一顆黑色的藥丸。\n");
        set("eff_msg",HIG "你覺得一陣陣苦味在嘴裡散開來...\n" NOR );
        }
        setup();
}

