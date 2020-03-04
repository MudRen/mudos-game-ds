inherit MOBROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_29_17",
	"south" : __DIR__"map_30_18",
	"north" : __DIR__"map_28_18",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cow_10" : 1,
	__DIR__"../npc/beast_cow_5" : 3,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_cow_5",
	__DIR__"../npc/beast_frog_3",
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

