inherit ROOM;
void create()
{
	set("short", "骨龍遺洞");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_2_25",
	"west" : __DIR__"map_3_24",
	"south" : __DIR__"map_4_25",
	"east" : __DIR__"map_3_26",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

