inherit ROOM;
void create()
{
	set("short", "���");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_2_11",
	"south" : __DIR__"map_3_10",
	"north" : __DIR__"map_1_10",
	"west" : __DIR__"map_2_9",
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

