inherit ROOM;
void create()
{
	set("short", "暗礁");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_9",
	"west" : __DIR__"map_9_7",
	"north" : __DIR__"map_8_8",
	]));
set("objects", ([__DIR__"../npc/eel" : 2,
	      __DIR__"../npc/shark":1,
    ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

