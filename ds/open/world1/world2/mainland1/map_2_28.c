inherit ROOM;
void create()
{
	set("short", "竹林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_27",
	"south" : __DIR__"map_3_28",
	"north" : __DIR__"map_1_28",
	"east" : __DIR__"map_2_29",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

