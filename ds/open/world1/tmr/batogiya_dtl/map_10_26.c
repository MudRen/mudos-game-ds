inherit ROOM;
void create()
{
	set("short", "廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_11_26",
	"west" : __DIR__"map_10_25",
	"north" : __DIR__"map_9_26",
	]));
    set("objects", ([
        __DIR__"npc/child.c" : 4,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

