inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_5_16",
	"west" : __DIR__"map_6_15",
	"east" : __DIR__"map_6_17",
	]));
	set("outdoors","land");
	set("objects", ([
          __DIR__"npc/cat" : 2, 
          __DIR__"npc/fetish" : 1, 
          __DIR__"npc/fetish_wizard" : 1, 
          __DIR__"npc/ents2" : 1, 
	]) );
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

