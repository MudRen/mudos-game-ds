inherit MOBROOM;
void create()
{
	set("short", "�x�|");
        set("long", @LONG

LONG
);
	set("exits",([
	"north" : __DIR__"map_15_32",
	"west" : __DIR__"map_16_31",
	]));
	set("objects", ([
	__DIR__"../npc/beast_pig_2" : 1,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",33);	
	set("mob_amount",3);
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

