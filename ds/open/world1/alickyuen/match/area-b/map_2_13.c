inherit ROOM;
void create()
{
	set("short", "雪地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_12",
	"east" : __DIR__"map_2_14",
	]));
	set("outdoors","snow");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

