inherit ROOM;
void create()
{
	set("short", "林中小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_7_17",
	"west" : __DIR__"map_6_16",
	]));
	set("outdoors","forest");
        set("objects",([
                __DIR__"npc/forest-garrison":1,
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

