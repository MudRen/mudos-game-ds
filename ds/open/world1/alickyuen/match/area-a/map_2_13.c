inherit ROOM;
void create()
{
	set("short", "森林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_12",
	"south" : __DIR__"map_3_13",
	"north" : __DIR__"map_1_13",
	]));
	set("outdoors","forest");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

