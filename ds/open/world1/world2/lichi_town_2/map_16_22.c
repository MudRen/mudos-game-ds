inherit ROOM;
void create()
{
	set("short", "櫃檯");
        set("long", @LONG
這裡是銀行的中央櫃檯。你看到櫃檯後面有許多金庫，這裡的戒備
非常森嚴，四處都有電眼監視，以確保民眾們的財產安全。
	===============================
	餘額查詢	<balance> 
	存款		<deposit 金額> 
	提款		<withdraw 金額>
	===============================
LONG
);
	set("exits",([
	"east" : __DIR__"map_16_23",
	"south" : __DIR__"map_17_22",
	"north" : __DIR__"map_15_22",
	]));
	set("objects",([
		__DIR__"../npc/malo_banker_15": 1,
	]));
	set("no_fight",1);
	set("no_kill",1);
	set("light",1);
        setup();
}
/*
string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}
*/
