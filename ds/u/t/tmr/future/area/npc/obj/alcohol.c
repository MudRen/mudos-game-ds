inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("酒管", ({ "alcohol tube","tube","alcohol" }) );
        set_weight(60);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("long", "一條小小的膠管，裡有著一個次空間來存水。\n");
            set("unit", "條");
            set("value", 50);       
            set("heal_ap",10);      
            set("water_remaining", 5);
        }
}

