inherit ROOM;
void create()
{
	set("short", "草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_37_42",
	"south" : __DIR__"map_38_43",
	"north" : __DIR__"map_36_43",
	"east" : __DIR__"map_37_44",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

