inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("蔘茶", ({ "tea" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一罐看來相當滋補的蔘茶.\n");
                set("unit","罐");
                    set("value",200);
           set("heal_ap",21);
                set("water_remaining",3);
        }
     setup();
}

