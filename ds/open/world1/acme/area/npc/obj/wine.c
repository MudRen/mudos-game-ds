inherit ITEM;
inherit F_WATER;
void create()
{
    set_name("女兒紅", ({ "red wine","wine" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
          set("long","這種酒十分是待嫁姑娘，在出傢時會拿出來宴請賓客的，\n"
        "所以稱之為「女兒紅」。\n");
	      set("unit", "瓶");
          set("value", 180);    
          set("heal_mp",20);
          set("water_remaining", 3);
	}
	setup();
}
