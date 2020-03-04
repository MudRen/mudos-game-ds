#include <ansi.h>;
#include <room.h>;
inherit __DIR__"room"; // 檔路 - alick
void create()
{
        set("short", HIC"情城池九言陣["HIW"在"HIC"]"NOR);
        set("long", @LONG
你正走在情城池的九言陣，只見得四週盡是濃霧彌漫，伸手不見五指
，在陣陣濃霧的正中央，站著一位白髮紅顏的絕世美女，濃霧在她的身旁
圍繞著就是近不了她的身旁五尺，看來那位女子也有相當的功力，但是你
覺得這個地方跟其他地方好像有一個地方不對勁，你也說不上有什麼地方
不同，一股毛毛的感覺從你心底處升起。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "按鈕" : "一個作用不明的裝置(push button)?\n"
]));

        set("exits", ([ /*中心點[臨]file_name room18*/
  "south" : __DIR__"room18", 
  "north"  : __DIR__"room27",
//  "northwest"  : __DIR__"room20",
//  "southeast"  : __DIR__"room21",
//  "southwest"  : __DIR__"room22",
//  "up"  : __DIR__"room23",
//  "down"  : __DIR__"room24",
//  "north"  : __DIR__"room25",
]));
set("light",1);
        set("objects", ([
 __DIR__"npc/win" : 1,
]));
        set("no_recall",1);
        setup();
}
void init()
{
      add_action("do_push","push");
}

int do_push(string arg)
{
       object me;
       me=this_player();
	if( arg != "button")
       return 0;
       else {
message_vision(HIG"$N伸手在東邊的一個按鈕上一按，$N立刻被一股強風吸入牆壁裡！\n"NOR,me);
       me->move(__DIR__"room26"); 
message_vision(HIY"$N的身型在一陣強風中逐漸清晰出來。\n"NOR,me);
          return 1;
        }
}


