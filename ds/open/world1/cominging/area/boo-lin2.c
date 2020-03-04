#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "步靈城中央");
        set("long",@LONG
這裡是步靈城的中央，這裡的聲音挺令人覺得有些許吵雜，不過卻
也有些女子的叫賣聲也很悅耳，但是跟男子粗壯的喊叫聲形成了相當的
對比，這也有些小小的孩子在向商人購買一些好喝的蜜糖水和好吃的甜
棗子，你也許想到小時和同伴一起嘻戲的情形，這邊的附近有一些專門
販賣日常生活用具的小販，你在倏地間彷彿看到地上有一些小孩不要的
玩具。
LONG
        );
        set("exits", ([
  "north" : __DIR__"boo-lin.c",
  "south" : __DIR__"boo-lin3.c",
]));
        set("item_desc",([
  "toy" : "一些你小時候雙親常購買給你的玩具，令你想到小時候天真無邪的\n情形，你可以試著撿(pick)看看。\n",
  "玩具": "一些你小時候雙親常購買給你的玩具，令你想到小時候天真無邪的\n情形，你可以試著撿看看。\n",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
        setup();
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me,toy;
        me = this_player();
        toy = new(__DIR__"npc/obj/toy.c");
        if( !arg ) return 0;
        if( arg!="toy" && arg!="玩具" ) return 0;
if( query_temp("gettoy") )
{
    return 0;
}

        message_vision("$N撿起一個玩具。\n",me);
        toy->move(me);
        set_temp("gettoy",1);
        this_object()->delete("item_desc");
        set("long",@LONG
這裡是步靈城的中央，這裡的聲音挺令人覺得有些許嘈雜，不過卻
也有些女子的叫賣聲也很悅耳，但是跟男子粗壯的喊叫聲形成了相當的
對比，這也有些小小的孩子在向商人購買一些好喝的密糖水和好吃的甜
棗子，你也許想到小時和同伴一起嘻戲的情形，這邊的附近有一些專門
販賣日常生活用具的小販。
LONG
        );
        call_out("delay",180,this_object());
        return 1;
}

void delay(object room)
{
        delete_temp("gettoy");
        set("long",@LONG
這裡是步靈城的中央，這裡的聲音挺令人覺得有些許嘈雜，不過卻
也有些女子的叫賣聲也很悅耳，但是跟男子粗壯的喊叫聲形成了相當的
對比，這也有些小小的孩子在向商人購買一些好喝的密糖水和好吃的甜
棗子，你也許想到小時和同伴一起嘻戲的情形，這邊的附近有一些專門
販賣日常生活用具的小販，你在倏地間彷彿看到地上有一些小孩不要的
玩具。
LONG
        );
        set("item_desc",([
  "toy" : "一些你小時候雙親常購買給你的玩具，令你想到小時候天真無邪的\n情形，你可以試著撿看看。\n",
  "玩具" : "一些你小時候雙親常購買給你的玩具，令你想到小時候天真無邪的\n情形，你可以試著撿看看。\n",
]));
        return;
}
