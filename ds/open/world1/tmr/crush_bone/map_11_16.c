inherit ROOM;
void create()
{
	set("short", "大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_15",
	"north" : __DIR__"map_10_16",
	]));
    set("objects", ([
        __DIR__"npc/orc_commander" : 4,
    ]));

	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

