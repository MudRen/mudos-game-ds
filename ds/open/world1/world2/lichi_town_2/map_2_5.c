inherit ROOM;
void create()
{
	set("short", "臥室");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_6",
	]));
	set("objects",([
		__DIR__"../obj/crystal_ball":1,
	]));
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

