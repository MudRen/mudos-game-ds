inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("速食麵", ({ "noodle" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗熱騰騰的速食麵，看來滿好吃的樣子。\n");
                set("unit", "碗");
                set("value", 40);  
                set("food_remaining",3);
                set("heal_hp",10);  
        }
}

