inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_34_4",
	"west" : __DIR__"map_35_3",
	"south" : __DIR__"map_36_4",
	"east" : __DIR__"map_35_5",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

