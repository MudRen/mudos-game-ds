inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("蚜蟲蜜", ({ "aphid liquid","liquid","aphid" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一份蚜蟲屁屁分泌出來的汁液，有好香好濃的味道喔！\n");
                set("unit","份");
        }
        set("value",0);
        set("heal_ap",20);
        set("water_remaining",3);
        setup();
}
