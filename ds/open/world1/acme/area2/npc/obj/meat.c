inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("西坡肉",({"si po meat","meat"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一個閒名全城的大塊牛肉，看起來十分可口。\n");
                set("unit", "個");
                set("value",100);
                set("heal_hp",10);
                set("heal_mp",10);
                set("food_remaining",5);
        }
   setup();
}
