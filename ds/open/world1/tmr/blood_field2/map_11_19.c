inherit ROOM;
void create()
{
	set("short", "血跡");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_11_18",
	"south" : __DIR__"map_12_19",
	"north" : __DIR__"map_10_19",
	]));
	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

