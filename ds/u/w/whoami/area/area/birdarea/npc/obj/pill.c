inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("大補丸", ({ "big pill","pill" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一顆黑呦呦的丸子，散發出一股香味•\n");
                set("unit","顆");
                set("value",200);
                set("heal_ap",50);
                set("food_remaining",3+random(3));
        }
}

