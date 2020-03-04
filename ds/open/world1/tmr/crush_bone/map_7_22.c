inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_22",
	"north" : __DIR__"map_6_22",
	]));
    set("objects", ([
        __DIR__"npc/orc" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

