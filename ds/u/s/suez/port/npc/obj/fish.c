inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("燻魚", ({ "fish" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "將魚燻乾了以後，不但便於保存，也增添了美味。\n");
                set("unit", "片");
                set("value", 20);       
                set("heal_hp",20);      
                set("food_remaining", 5);
        }
        setup();
}


