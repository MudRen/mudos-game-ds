inherit ROOM;
void create()
{
	set("short", "幽暗地道");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_8",
	"east" : __DIR__"map_4_10",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

