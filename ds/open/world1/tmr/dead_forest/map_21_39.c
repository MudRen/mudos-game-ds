inherit ROOM;
void create()
{
	set("short", "破舊木屋");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_20_39",
	]));
	set("objects" , ([
		__DIR__"npc/yang-oldman" : 1
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

