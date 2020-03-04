inherit MOBROOM;
void create()
{
	set("short", "�ܮw");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_31",
	]));
	set("objects", ([
	__DIR__"../npc/beast_roach_2" : 1,
	]) );
        set("light",1);
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_mosquito_1",
	__DIR__"../npc/beast_roach_2",
	__DIR__"../npc/beast_rat_3",
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

