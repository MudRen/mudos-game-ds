inherit ROOM;
void create()
{
	set("short", "廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_24",
	"north" : __DIR__"map_10_25",
	"east" : __DIR__"map_11_26",
	]));
    set("objects", ([
        __DIR__"npc/child.c" : 2,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

