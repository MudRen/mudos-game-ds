inherit ROOM;
void create()
{
	set("short", "���ͦ�");
        set("long", @LONG

LONG
);
	set("exits",([
	"east" : __DIR__"map_5_13",
	"south" : __DIR__"map_6_12",
	"north" : __DIR__"map_4_12",
	"west" : __DIR__"map_5_11",
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

