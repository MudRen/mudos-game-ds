inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_20_39",
	"west" : __DIR__"map_21_38",
	"south" : __DIR__"map_22_39",
	"east" : __DIR__"map_21_40",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

