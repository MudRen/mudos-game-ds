inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"south" : __DIR__"map_2_15",
	"west" : __DIR__"map_1_14",
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

