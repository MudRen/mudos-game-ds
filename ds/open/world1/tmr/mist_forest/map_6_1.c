inherit ROOM;
void create()
{
	set("short", "迷霧森林-小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_5_1",
	"south" : __DIR__"map_7_1",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

