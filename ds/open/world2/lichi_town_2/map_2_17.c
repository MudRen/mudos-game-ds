inherit ROOM;
void create()
{
	set("short", "警衛室");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_17",
	]));
	set("objects", ([
	__DIR__"../npc/malo_guard_18" : 1,
	]) );
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

