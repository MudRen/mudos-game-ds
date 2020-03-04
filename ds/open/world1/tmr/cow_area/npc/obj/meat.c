
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "母牛肉乾" , ({ "beef meat","meat", "_BEEF_MEAT_" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 500);
                set("long", "這是一片好吃的牛肉乾，是從母牛身上切下來的新鮮肉乾。\n");
                set("unit", "片");
                set("food_remaining", 5); 
                set("heal_ap", 150);   
                set("heal_mp", 150);   
                set("heal_hp", 150);   
        }
        setup();
}

