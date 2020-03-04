inherit ROOM;
void create()
{
	set("short", "龍泉廣場");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_23",
	"south" : __DIR__"map_4_22",
	"north" : __DIR__"map_2_22",
	"west" : __DIR__"map_3_21",
	]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

