inherit ROOM;
void create()
{
	set("short", "荒島上的小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_5_5",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/barbarian-captain2":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

