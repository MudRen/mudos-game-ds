inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_3_12",
	"south" : __DIR__"map_4_11",
	"north" : __DIR__"map_2_11",
	"west" : __DIR__"map_3_10",
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

