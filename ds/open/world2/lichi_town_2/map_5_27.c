inherit ROOM;
void create()
{
	set("short", "旅館櫃檯");
        set("long", @LONG
你來到旅館的櫃檯。這棟旅館生意十分興隆，地毯與弔燈看起來
也很高級，無怪乎來往的旅客臉上洋溢著滿意的笑容。櫃檯旁邊有個
牌子寫著:
	==========================
	訂房休息	checkin
	商品清單	list
	購買商品	buy <商品>
	==========================
	
LONG
);
	set("exits",([
	"south" : __DIR__"map_6_27",
	"north" : __DIR__"map_4_27",
	"west" : __DIR__"map_5_26",
	]));
	set("objects", ([
		__DIR__"../npc/malo_inner_12": 1,
	]));
	set("no_fight",1);
        set("valid_startroom", 1);
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