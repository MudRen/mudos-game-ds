inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("營養針", ({ "Vitamin pin","pin" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一枝針，看來不大好吃.......\n");
                set("unit", "個");
                  set("value", 40);  
                     set("food_remaining", 5);
                  set("heal_hp",5);  
  set("eat_msg","$N把針內的東東擠出來,然後吞下...好嘔心...\n");
        set("finish_eat_msg","$N將針內餘下的東東吃光了。\n");
        }
setup();
}
