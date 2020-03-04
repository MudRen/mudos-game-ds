inherit ROOM;
void create()
{
	set("short", "野蠻人的小屋");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_9_15",
	"west" : __DIR__"map_10_14",
	"east" : __DIR__"map_10_16",
	"south" : __DIR__"map_11_15",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian":4,
        ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

