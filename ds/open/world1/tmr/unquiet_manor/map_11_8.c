inherit ROOM;
void create()
{
	set("short", "碎石小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_12_8",
	"north" : __DIR__"map_10_8",
	"west" : __DIR__"map_11_7",
	"east" : __DIR__"map_11_9",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

