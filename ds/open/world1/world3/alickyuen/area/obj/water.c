inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("存水盒", ({ "water box","box" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個用來存放水的盒子。\n");
                set("unit", "瓶");
                  set("value", 40);       
                  set("heal_ap",5);      
                   set("water_remaining", 5);
          set("drink_msg","$N打開盒子的蓋\子，然後喝了幾口。\n");
        set("finish_drink_msg","$N將盒子裡餘下的水喝光了。\n");
        }
}
