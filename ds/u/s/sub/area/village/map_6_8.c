inherit ROOM;
void create()
{
	set("short", "碎石路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_6_7",
	"south" : __DIR__"map_7_8",
	"north" : __DIR__"map_5_8",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

