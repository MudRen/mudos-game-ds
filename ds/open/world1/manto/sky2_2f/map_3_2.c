inherit ROOM;
void create()
{
	set("short", "天地會總壇二樓");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_4_2",
	"north" : __DIR__"map_2_2",
	]));
	set("light",1);
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

