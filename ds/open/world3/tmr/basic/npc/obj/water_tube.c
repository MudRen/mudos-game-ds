inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("壓縮水管", ({ "water tube","tube" }) );
        set_weight(60);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("long", "一條小小的膠管，裡頭壓縮著充分的清水。\n");
            set("unit", "條");
            set("value", 50);       
            set("heal_ap",2);      
            set("water_remaining", 3);
        }
}



