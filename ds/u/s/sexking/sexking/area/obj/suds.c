inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("壽司",({"chicken leg","leg"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是日本的小吃之一，味道還不錯。\n");
                set("unit", "塊");
                  set("value",70);
                set("heal_hp",20);
               set("food_remaining",2);
        }
     setup();
}


