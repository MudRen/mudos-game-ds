inherit ROOM;

void create()
{
	set("short", "井中密道");
        set("long", @LONG
這個井似乎乾了很久，井底長了許多長長的雜草。
LONG
);
	set("exits",([
		"east" : __DIR__"well5",
		"west" : __DIR__"well7",
		"north" : __DIR__"well8",
		"south" : __DIR__"well9",
	]));

    set("objects", ([
       // __DIR__"../npc/beast_frog_3" : 1,
    ]));
        setup();
}
