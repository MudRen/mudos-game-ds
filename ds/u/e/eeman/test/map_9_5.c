inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_9_6",
	"south" : __DIR__"map_10_5",
	"north" : __DIR__"map_8_5",
	"west" : __DIR__"map_9_4",
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

