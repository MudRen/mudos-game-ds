inherit ROOM;
void create()
{
	set("short", "廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_24",
	"east" : __DIR__"map_9_25",
	]));
    set("objects", ([
        __DIR__"npc/stake" : 3,
    ]));

        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

