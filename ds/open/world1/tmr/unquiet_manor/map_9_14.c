inherit ROOM;
void create()
{
	set("short", "無寧莊園-墳場");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_14",
	"north" : __DIR__"map_8_14",
	"west" : __DIR__"map_9_13",
	"east" : __DIR__"map_9_15",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

