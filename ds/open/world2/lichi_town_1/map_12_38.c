inherit MOBROOM;
void create()
{
	set("short", "�ѹD");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_13_38",
	"north" : __DIR__"map_11_38",
	]));
	set("objects", ([
	__DIR__"../npc/beast_ladybug_2" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_mosquito_1",
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

