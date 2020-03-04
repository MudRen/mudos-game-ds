#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"騰空書院"NOR);

 set("long",@LONG
你走進了另一間房間, 發現這裡是一處空中庭院, 到處鳥語花香, 
你看到的花卉顯然花期不同, 由此可以看出這裡似乎沒有四季之分, 
你再仔細一看, 發現在花叢(flowers)間一根突起的木頭(wood)顯然
寫了些字, 你一想了想.... 算了, 先看看吧....
LONG
    );
 set("exits",([ "west":__DIR__"school1.c",
                "up":__DIR__"school3.c",
    ]));
 set("item_desc",([
        "wood":"你看了看這根木頭, 發現背面是平的, 上面寫著: 戰鬥技巧, ....
哇! 後面的字看不清了....怎麼辦呢? 對了, 人家不是說心誠則靈嗎? 用看看老
天(god)可不可以幫你吧! .\n",
        "god":"你看了看晴空, 心中不禁祈禱自己玩DS一路順利, 忽然, 啪! 的一聲, 
一本書(book)掉了下來.....\n",
        "book":"..這本書是要教你如何戰鬥, 也是天神被你誠心感動而掉下的書..
希望你好好看一下. 首先下 search flowers 這個指令. 會跑出一隻蝴蝶, 對它下kill
指令, 那就是戰鬥的實況, 戰鬥前應先用consider鑑定一下敵人, 再開戰, 那萬一不幸
陣亡怎麼辦呢? 你死後會到一個有兩個雕像的地方....其中一個是生命之神, 一個是死
亡之神, 聰明如你, 應該知道要拜哪一個吧!?反正錯了再試嘛...., 對了, 殺死敵人後
不要忘記奉獻(sac)他的屍體(corpse)喔!但可別搶別人殺死的人的屍體喔...\n",
    ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}
void init()
{
        add_action("do_search","search");
}
int do_search(string arg)
{
        object me;
        object butterfly;
        me=this_player();
        if(arg != "flowers") return 0;
	if(me->query_temp("find_butter")) return notify_fail("你仔細的找了找花叢, 什麼都沒找到。\n");
	if(!me->query_temp("find_butter"))
	{
        	message_vision("$N仔細的在花叢中尋找東西, 花叢間突然飛出一隻小蝴蝶。\n\n",me);
		butterfly=new(__DIR__"npc/butterfly.c");
		butterfly->move(__DIR__"school2.c");
		me->set_temp("find_butter",1);
		return 1;
	}
}
