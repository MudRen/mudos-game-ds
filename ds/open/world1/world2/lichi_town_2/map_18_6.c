inherit MOBROOM;
void create()
{
	set("short", "��W");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_18_7",
	"north" : __DIR__"map_17_6",
	"west" : __DIR__"map_18_5",
	]));
	set("objects", ([
	__DIR__"../npc/beast_spider_5" : 3,
	]) );
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_bug_1",
	__DIR__"../npc/beast_spider_5",
	__DIR__"../npc/beast_spider_8",
	__DIR__"../npc/beast_butterfly_3",
	}) );
        setup();
	set("map_long",1);     //show map as long
}

