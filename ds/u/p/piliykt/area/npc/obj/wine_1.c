inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("梅花酒", ({ "flower wine","wine" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一瓶香氣四溢的酒，令人心養養的。\n");
                set("unit","瓶");
                    set("value",200);
           set("heal_ap",30);
                set("water_remaining",5);
        }
     setup();
}


