inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_34_24",
	"south" : __DIR__"map_35_25",
	"north" : __DIR__"map_33_25",
	"east" : __DIR__"map_34_26",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

