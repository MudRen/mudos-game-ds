inherit ROOM;
void create()
{
	set("short", "木板橋");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_3",
	"east" : __DIR__"map_7_5",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

