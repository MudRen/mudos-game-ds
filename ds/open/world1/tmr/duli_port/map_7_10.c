inherit ROOM;
void create()
{
	set("short", "杜尼港-街道");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_8_10",
	"north" : __DIR__"map_6_10",
	]));
	set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

