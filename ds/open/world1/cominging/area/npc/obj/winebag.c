inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("酒袋", ({ "wine bag","bag" }) );
        set_weight(1180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一個牛皮製的袋子，內頭裝的可醉人的酒水。\n");
                set("unit", "袋");
                set("value", 100);
		set("volume",2);
                set("heal_mp",10);
                set("water_remaining", 5);
        }
	setup();
}
