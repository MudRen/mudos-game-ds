inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("蜈蚣酒", ({ "scolopendrid wine","wine"}) );
        set_weight(100);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long", "百毒蜈蚣做成的酒，此酒非常之強烈。");
                set("unit", "瓶");
        }
                set("value", 40);       
                set("heal_mp",0);      
                set("heal_ap",34);
                set("heal_hp",5);
                set("water_remaining", 5);
       setup();
}

