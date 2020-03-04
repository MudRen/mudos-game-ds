inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_2",
	"south" : __DIR__"map_12_1",
	"north" : __DIR__"map_10_1",
	]));
    set("objects", ([
        __DIR__"npc/orc_follower" : 4,
        __DIR__"npc/orc_thousand_leader" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

