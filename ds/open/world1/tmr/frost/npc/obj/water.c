inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("山泉水", ({ "spring water","water" }));
          set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一瓶乾淨的山泉水，喝起來帶有點甜味。\n");
                set("unit","瓶");
        }
        set("value",10);
          set("heal_ap",5);
        set("water_remaining",2);
        setup();
}
