inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_10_11",
	"south" : __DIR__"map_11_10",
	"north" : __DIR__"map_9_10",
	"west" : __DIR__"map_10_9",
	]));
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

