inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("熱開水", ({ "hot water" , "water" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一杯熱開水...不然你以為會是啥？...\n");
                set("unit","杯");
                    set("value",100);
                set("water_remaining",10);
        }
     setup();
}

