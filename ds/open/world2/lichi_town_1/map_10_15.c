inherit ROOM;
void create()
{
	set("short", "龍泉廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_16",
	"south" : __DIR__"map_11_15",
	"north" : __DIR__"map_9_15",
	"west" : __DIR__"map_10_14",
	]));
	set("objects", ([
	__DIR__"../npc/malo_guard_18" : 1,
	]) );
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

