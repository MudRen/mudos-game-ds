inherit ROOM;
void create()
{
	set("short", "大廳");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_16",
	"west" : __DIR__"map_11_14",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

