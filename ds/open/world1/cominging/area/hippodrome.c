#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
// 不可以這樣寫. 許多玩家跑到了 void!
//	object me;
//	string a;
//	me=this_player();
//
//	if ( me->query("level") > 7 )a=COMINGING_PAST+"area/level20";
//	if ( me->query("level") < 7 )a="/obj/void.c";

	set("short", "步靈城附屬競技之場");
	set("long",@LONG
這裡是步靈城上附屬的競技場，也可說為一般冒險者或者是武術家
的練武之地，這裡已有百年的歷史，不過裝潢依舊如新的一般，你一進
來就被裡面大批的人群所擁擠，這裡的顧客數量也可稱的上是數一數二
的，人稱步靈有疾技，孟村有八極，天城有神武，就是其中疾技中的技
了，北邊就是許多冒險者所嚮往的訓練的地區，似乎景色有點不太對勁
。內部大廳的門檻上有一個牌子(sign)有價位表。
LONG
	);
	set("item_desc", ([
	"sign" : HIY"
這裡的價位表：以等級高低區別。
(開幕大特價一律 免費)

"NOR,
	]));
        set("no_map", 1);
	set("light", 1);
	set("exits", ([
  "north" : __DIR__"level20",
  "west" : __DIR__"bsouth3.c",
//  "east" : __DIR__"fightingroom.c",
        "east" : "/open/world1/alickyuen/match/entrance",
]));
	setup();
}
/*
void init()
{
	add_action("do_pay","pay");
}
*/
int valid_leave(object me, string dir)
{
	string gender;
	gender=me->query("gender");
	if ( gender=="男性" ) gender="你";
	if ( gender=="女性" ) gender="妳";
	if ( me->query("age") > 50 ) gender="您";
	
	if( dir=="north" )
	{
		if(me->query("level")<10)
		{
			message_vision("在旁的武術家看到$N要進入危險的競技場，馬上上來喝止$N，\n"+"並對$N說：這位"+RANK_D->query_respect(me)+"，裡邊可是危險的很，請"+gender+"不要亂闖。\n", me);
			return notify_fail("那裡只有高等級才能進去。\n");
		}
//        if(me->query("level")>30)
//            return notify_fail("競技場已無法提供"+gender+"更好的訓練了。\n");
		}
        return ::valid_leave(me, dir);
}
