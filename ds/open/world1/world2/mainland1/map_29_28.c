inherit ROOM;
void create()
{
	set("short", "榕樹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_29_27",
	"north" : __DIR__"map_28_28",
	"east" : __DIR__"map_29_29",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

