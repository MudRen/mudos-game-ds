inherit ROOM;
void create()
{
	set("short", "針葉林");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_18_17",
	"south" : __DIR__"map_19_18",
	"north" : __DIR__"map_17_18",
	"east" : __DIR__"map_18_19",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

