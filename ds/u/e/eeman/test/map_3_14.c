inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_15",
	"south" : __DIR__"map_4_14",
	"north" : __DIR__"map_2_14",
	"west" : __DIR__"map_3_13",
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

