inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("一番味拉麵",({"one noodles","noodles"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一碗很好吃的拉麵，十分流行。\n");
                set("unit", "碗");
                  set("value",160);
                set("heal_hp",40);
               set("food_remaining",2);
        }
     setup();
}
