inherit MOBROOM;
void create()
{
	set("short", "��|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_38",
	"south" : __DIR__"map_17_37",
	]));
	set("objects", ([
	__DIR__"../npc/beast_spider_8" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_spider_5",
	__DIR__"../npc/beast_roach_2",
	}) );
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

