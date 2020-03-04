inherit MOBROOM;
void create()
{
	set("short", "�x�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_16_32",
	"north" : __DIR__"map_15_31",
	"west" : __DIR__"map_16_30",
	]));
	set("objects", ([
	__DIR__"../npc/beast_pig_8" : 1,
	__DIR__"../npc/beast_pig_2" : 2,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",4);	
	set("mob_object",({	
	__DIR__"../npc/beast_pig_2",
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

