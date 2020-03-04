inherit ROOM;
void create()
{
	set("short", "野蠻人的小屋");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_5",
	"south" : __DIR__"map_9_4",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian":2,
                __DIR__"npc/barbarian-captain":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

