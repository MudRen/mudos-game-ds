inherit ROOM;
void create()
{
	set("short", "林中草地");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_10_7",
	"west" : __DIR__"map_9_6",
	]));
        set("objects",([
                __DIR__"npc/obj/branche":1,
        ]));

	set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

