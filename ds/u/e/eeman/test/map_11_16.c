inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_11_17",
	"south" : __DIR__"map_12_16",
	"north" : __DIR__"map_10_16",
	"west" : __DIR__"map_11_15",
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

