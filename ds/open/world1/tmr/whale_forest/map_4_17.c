inherit ROOM;
void create()
{
	set("short", "洞內小路");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_4_16",
	"north" : __DIR__"map_3_17",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

