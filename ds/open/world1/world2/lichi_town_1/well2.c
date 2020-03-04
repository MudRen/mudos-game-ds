inherit ROOM;

void create()
{
	set("short", "水井中");
        set("long", @LONG
這個井似乎乾了很久，井底長了許多長長的雜草。
LONG
);
	set("exits",([
		"east" : __DIR__"well1",
		"up" : __DIR__"well3",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}

int room_effect(object me)
{
	object room=find_object(__DIR__"map_5_6");
	return room->handle_well_effect(me);
}

int valid_leave(object me, string dir)
{
	object room=find_object(__DIR__"map_5_6");
	if( dir=="east" && room->query_well())
	{
		if(random(me->query_skill("swim"))<15) return notify_fail("你的游泳技巧太差，游不過去。\n");
	}
	return ::valid_leave(me, dir);
}