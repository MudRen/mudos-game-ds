inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_19_38",
	"south" : __DIR__"map_20_39",
	"north" : __DIR__"map_18_39",
	"east" : __DIR__"map_19_40",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

