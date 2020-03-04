inherit MOBROOM;
void create()
{
	set("short", "�ܮw");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_32",
	"north" : __DIR__"map_7_31",
	"west" : __DIR__"map_8_30",
	]));
	set("objects", ([
	__DIR__"../npc/beast_spider_5" : 1,
	]) );
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_spider_8",
	__DIR__"../npc/beast_roach_2",
	__DIR__"../npc/beast_rat_3",
	__DIR__"../npc/beast_spider_5",
	}) );
        setup();
	set("map_long",1);     //show map as long
}

