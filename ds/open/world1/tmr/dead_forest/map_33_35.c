inherit ROOM;
void create()
{
	set("short", "小徑");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_33_36",
	"south" : __DIR__"map_34_35",
	"west" : __DIR__"map_33_34",
	]));
        set("objects",([
                __DIR__"npc/mei-feng.c" : 1,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

