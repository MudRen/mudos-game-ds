inherit ROOM;
void create()
{
	set("short", "湖中");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_2_1",
	"south" : __DIR__"map_3_2",
	"north" : __DIR__"map_1_2",
	"east" : __DIR__"map_2_3",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

