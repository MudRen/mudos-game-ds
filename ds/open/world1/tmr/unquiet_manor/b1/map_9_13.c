inherit ROOM;
void create()
{
	set("short", "血池");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_13",
	"north" : __DIR__"map_8_13",
	"west" : __DIR__"map_9_12",
	"east" : __DIR__"map_9_14",
	]));
        set("objects", ([
                "/open/world1/tmr/unquiet_manor/npc/insect" : 2
        ]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

