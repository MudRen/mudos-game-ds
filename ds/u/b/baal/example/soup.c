inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("雞湯", ({ "chicken soup","soup" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","一碗不大不小的雞湯, 好香喔 ~~~~ \n");
		set("unit","碗");
        }
	set("value",40);
	set("heal_ap",10);
	set("water_remaining",2);
	setup();
}
