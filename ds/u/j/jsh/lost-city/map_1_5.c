inherit ROOM;
void create()
{
	set("short", "石板路");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_1_6",
	"west" : __DIR__"map_1_4",
	"south" : __DIR__"map_2_5",
	"north" : __DIR__"map_0_5",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

