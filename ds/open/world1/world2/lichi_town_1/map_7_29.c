inherit ROOM;
void create()
{
	set("short", "巷道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_29",
	"north" : __DIR__"map_6_29",
	"west" : __DIR__"map_7_28",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

