inherit ROOM;
void create()
{
	set("short", "無寧莊園-墳場");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_12",
	"west" : __DIR__"map_16_11",
	"east" : __DIR__"map_16_13",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

