inherit ROOM;
void create()
{
	set("short", "骨龍妖霧");
        set("long", @LONG
你正走在骨龍妖霧之中，四陣紫煙瀰漫，伸手難見五指。
LONG
);
	set("exits",([
	"north" : __DIR__"map_2_17",
	"west" : __DIR__"map_3_16",
	"south" : __DIR__"map_4_17",
	"east" : __DIR__"map_3_18",
	]));
	set("outdoors","land");
	set("objects", ([
		__DIR__"npc/ents2" : 1, 
	]) );
        setup();
        set("map_long",1);     //show map as long
}

