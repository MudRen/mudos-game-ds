inherit MOBROOM;
void create()
{
	set("short", "�Q����");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_21",
	"south" : __DIR__"map_6_20",
	"north" : __DIR__"map_4_20",
	"west" : __DIR__"map_5_19",
	]));
	set("objects", ([
	__DIR__"../npc/beast_fish_3" : 2,
	]) );
        set("light",1);
        set("outdoors","land");
	set("chance",53);	
	set("mob_amount",3);	
	set("mob_object",({	
	__DIR__"../npc/beast_fish_3",
	__DIR__"../npc/beast_fish_1",
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

