inherit ROOM;
void create()
{
	set("short", "沙漠");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_6_5",
	"north" : __DIR__"map_4_5",
	]));
	set("outdoors","desert");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

