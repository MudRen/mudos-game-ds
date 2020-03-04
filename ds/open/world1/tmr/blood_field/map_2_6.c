inherit ROOM;
void create()
{
	set("short", "骨龍遺洞");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_1_6",
	"west" : __DIR__"map_2_5",
	"south" : __DIR__"map_3_6",
	"east" : __DIR__"map_2_7",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

