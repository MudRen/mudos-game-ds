inherit ROOM;
void create()
{
	set("short", "巷道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_14_21",
	"north" : __DIR__"map_12_21",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

