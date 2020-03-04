inherit MOBROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_31_17",
	"south" : __DIR__"map_32_18",
	"north" : __DIR__"map_30_18",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cow_10" : 2,
	__DIR__"../npc/beast_cow_5" : 1,
	]) );
        set("outdoors","land");
	set("chance",43);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_cow_10",
	__DIR__"../npc/beast_cow_5",
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

