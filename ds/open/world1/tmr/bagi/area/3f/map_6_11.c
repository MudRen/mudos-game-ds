inherit ROOM;
void create()
{
	set("short", "寒日洞三層");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_10",
	"east" : __DIR__"map_6_12",
	"south" : __DIR__"map_7_11",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

