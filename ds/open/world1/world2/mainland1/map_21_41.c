inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_21_40",
	"south" : __DIR__"map_22_41",
	"north" : __DIR__"map_20_41",
	"east" : __DIR__"map_21_42",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

