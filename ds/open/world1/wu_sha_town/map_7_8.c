inherit ROOM;
void create()
{
	set("short", "海流");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_7_9",
	"south" : __DIR__"map_8_8",
	]));
 set("objects", ([__DIR__"../npc/carp" : 2,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

