inherit MOBROOM;
void create()
{
	set("short", "���s��");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_20",
	"north" : __DIR__"map_0_20",
	"west" : __DIR__"map_1_19",
	]));
	set("outdoors","land");
	set("objects", ([
	__DIR__"../npc/beast_butterfly_1" : 2,
	]) );
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_butterfly_1",
	__DIR__"../npc/beast_ladybug_2",
	__DIR__"../npc/beast_dove_1",
	__DIR__"../npc/beast_swallow_2",
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

