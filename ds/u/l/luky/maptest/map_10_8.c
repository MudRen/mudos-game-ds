inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
這裡是一塊尚未開發的空地。

LONG
);
	set("exits",([
	"west" : __DIR__"map_10_7",
	"south" : __DIR__"map_11_8",
	"north" : __DIR__"map_9_8",
	"east" : __DIR__"map_10_9",
	]));
        set("out_doors","land");
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}

