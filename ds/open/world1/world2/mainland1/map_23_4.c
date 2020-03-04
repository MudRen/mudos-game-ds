inherit MOBROOM;
void create()
{
	set("short", "��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_23_5",
	]));
	set("objects", ([
	__DIR__"../npc/beast_pig_18" : 1,
	__DIR__"../npc/beast_pig_7" : 2,
	]) );
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_pig_7",
	__DIR__"../npc/beast_pig_3",
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

