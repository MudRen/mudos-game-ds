inherit ROOM;
void create()
{
	set("short", "沙地");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_34_3",
	"east" : __DIR__"map_35_4",
	]));
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

