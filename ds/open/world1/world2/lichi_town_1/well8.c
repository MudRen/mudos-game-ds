inherit ROOM;

void create()
{
	set("short", "井中密道");
        set("long", @LONG
這個井似乎乾了很久，井底長了許多長長的雜草。
LONG
);
	set("exits",([
		"south" : __DIR__"well6",
		"west" : __DIR__"well11",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}
