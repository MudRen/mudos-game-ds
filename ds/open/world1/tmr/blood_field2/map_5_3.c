inherit ROOM;
void create()
{
	set("short", "骨龍遺洞");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_4",
	"west" : __DIR__"map_5_2",
	"south" : __DIR__"map_6_3",
	"north" : __DIR__"map_4_3",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

