inherit ROOM;
void create()
{
	set("short", "石室");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_8",
	]));
        set("objects",([
                __DIR__"npc/song-yu" : 1,
                __DIR__"npc/bandit3" : 3,
        ]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

