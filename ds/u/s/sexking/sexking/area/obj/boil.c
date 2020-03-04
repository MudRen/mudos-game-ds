inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("關東煮", ({ "gun don boil","boil" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long", "這是碗充滿日本風味的關東煮，裡面有很多小吃，熱呼呼的十分可口。\n");
                set("unit", "碗");
                set("eat_msg","$N將$n裡的黑輪拿出來一口氣啃了下去。\n");
                set("finish_msg","$N將$n中的米血拿出來一口氣啃了下去。\n");
        set("value", 200);
        set("heal_ap",30);
        set("heal_hp",30);
        set("food_remaining", 2);
}
setup();
}
