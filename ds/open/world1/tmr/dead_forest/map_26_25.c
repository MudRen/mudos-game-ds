inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_26_24",
	"north" : __DIR__"map_25_25",
	]));
        set("objects",([
                __DIR__"npc/corpse.c" : 4 ,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

