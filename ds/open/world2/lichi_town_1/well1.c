inherit ROOM;

void create()
{
	set("short", "水井中");
        set("long", @LONG
這個井似乎乾了很久，井底長了許多長長的雜草。
LONG
);
	set("exits",([
		"west" : __DIR__"well2",
	]));
        set("item_desc",([      
        "井壁" : "這井壁(wall)滿是坑洞和缺口，看來不難攀爬(climb)。\n",
        "wall" : "這井壁(wall)滿是坑洞和缺口，看來不難攀爬(climb)。\n",
        ])      );

    set("objects", ([
       __DIR__"../npc/beast_frog_3" : 1,
    ]));
	set("outdoors","land");
	set("no_weather",1);
        setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	if(!arg) return notify_fail( "你想爬(climb)什麼?\n");
	if(arg=="wall" || arg =="井壁")
	{
		message_vision("$N沿著井壁小心翼翼的爬了上去。\n",this_player());
		this_player()->move(__DIR__"map_5_6");
		if(!this_player()->query_temp("invis"))
			tell_room(environment(this_player()),this_player()->name()+"從井底爬了上來。\n",({this_player()}));
		return 1;
	}
	write("你想爬(climb)什麼?\n");
	return 1;
}

int room_effect(object me)
{
	object room=find_object(__DIR__"map_5_6");
	return room->handle_well_effect(me);
}

int valid_leave(object me, string dir)
{
	object room=find_object(__DIR__"map_5_6");
	if( dir=="west" && room->query_well())
	{
		if(random(me->query_skill("swim"))<15) return notify_fail("你的游泳技巧太差，游不過去。\n");
	}
	return ::valid_leave(me, dir);
}