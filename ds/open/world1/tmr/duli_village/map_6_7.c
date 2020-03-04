inherit ROOM;
void create()
{
	set("short", "魚村石路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_6",
	"east" : __DIR__"map_6_8",
	"south" : __DIR__"map_7_7",
	"north" : __DIR__"map_5_7",
	]));
        set("objects",([
                __DIR__"npc/fisherman":2,
        ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

