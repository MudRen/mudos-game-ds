inherit MOBROOM;
void create()
{
	set("short", "�ѹD");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_13_28",
	"south" : __DIR__"map_14_27",
	"north" : __DIR__"map_12_27",
	]));
	set("objects", ([
	__DIR__"../npc/beast_dove_1" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_dove_1",
	__DIR__"../npc/beast_sparrow_1",
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

