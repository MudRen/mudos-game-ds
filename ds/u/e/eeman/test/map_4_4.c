inherit ROOM;
void create()
{
	set("short", "�_��L");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_4_5",
	"south" : __DIR__"map_5_4",
	"north" : __DIR__"map_3_4",
	"west" : __DIR__"map_4_3",
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

