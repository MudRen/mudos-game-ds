inherit ROOM;
void create()
{
	set("short", "高山");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_0",
	"east" : __DIR__"map_4_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

