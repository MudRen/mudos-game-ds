inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_21_3",
	"west" : __DIR__"map_22_2",
	"south" : __DIR__"map_23_3",
	"east" : __DIR__"map_22_4",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

