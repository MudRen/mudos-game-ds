inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("四神湯", ({ "soup" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗香氣四溢的四神湯，令人垂涎三尺。\n");
                set("unit","碗");
                    set("value",180);
           set("heal_ap",20);
                set("water_remaining",3);
        }
     setup();
}
