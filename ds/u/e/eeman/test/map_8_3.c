inherit ROOM;
void create()
{
	set("short", "�۪O��");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_8_4",
	"south" : __DIR__"map_9_3",
	"north" : __DIR__"map_7_3",
	"west" : __DIR__"map_8_2",
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

