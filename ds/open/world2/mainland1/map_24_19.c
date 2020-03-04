inherit MOBROOM;
void create()
{
	set("short", "��a");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_24_18",
	"north" : __DIR__"map_23_19",
	]));
	set("objects", ([
	__DIR__"../npc/beast_cow_14" : 1,
	__DIR__"../npc/beast_frog_3" : 1,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_pig_7",
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

