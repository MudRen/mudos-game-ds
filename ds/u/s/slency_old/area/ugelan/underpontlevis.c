// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "小土丘");
	set("long",@LONG
這裡是吊橋下角落的一處小土丘，剛好可供一些人站立，你身旁的
土壁似乎有些奇怪，有一個隱約的門形在泥土後面，牆旁有一條草繩，
應該可以借此爬回吊橋上。
LONG
);
	set("item_desc" , ([ /* sizeof() == 2 */
	"土壁" : "一個佈滿泥沙的土牆，土牆後有一到鐵門。\n" ,
	"鐵門" : "一個生�蛌瘍K門，它似乎是鎖著的。\n" ,
	]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	if(arg != "草繩") return 0;
	write("你手抓草繩，腳用力一蹬躍上了吊橋。\n\n");
	this_player()->move(__DIR__"pontlevis");
	return 1;
}
