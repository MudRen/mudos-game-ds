inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "生血肉" , ({ "blood meat","meat", "_BLOOD_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 80);
                set("long", "這是一塊還滴著血的生肉，有股作嘔的腥味。\n");
                set("unit", "塊");
                set("food_remaining", 5); 
                set("heal_ap",10);   
                  set("heal_mp",10);   
        }
        setup();
}
