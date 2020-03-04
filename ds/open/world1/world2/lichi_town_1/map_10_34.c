inherit ROOM;
void create()
{
	set("short", "梅龍鎮");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_35",
	"north" : __DIR__"map_9_34",
	"west" : __DIR__"map_10_33",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cat_2" : 2,
	]) );
        set("light",1);
        set("outdoors","land");
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

