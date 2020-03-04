// cookie.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("點心", ({ "cookie" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個看起來蠻好吃的點心。\n");
                set("unit", "個");
                set("value", 0);       //參考價格為回復點數總和除以5
                set("heal_hp",10);      //可以是"heal_hp"或是"heal_mp",也可以都有.
                set("heal_mp",10);
                set("food_remaining", 2);
        }
        setup();
}

