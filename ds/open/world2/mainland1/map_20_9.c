inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_20_8",
	"south" : __DIR__"map_21_9",
	"north" : __DIR__"map_19_9",
	"east" : __DIR__"map_20_10",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

