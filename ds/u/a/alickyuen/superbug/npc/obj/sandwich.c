inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("三明治", ({ "sandwich" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個包著豬肉、蔬菜的三明治，看來十分可口。\n");
                set("unit", "個");
                set("value", 30);  
                set("food_remaining",3);
                set("heal_hp",5);  
        }
}


