inherit ROOM;
void create()
{
	set("short", "走道");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_19_13",
	"west" : __DIR__"map_19_11",
	"south" : __DIR__"map_20_12",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

