#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"抓狂廁所"NOR);
        set("long", @LONG
這裡是一間很臭的廁所..你得趕快逃跑才行ㄛ..
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"workroom3",
        ]));
        set("item_desc",([
        "抓狂馬桶":"一個很臭的馬桶,似乎很久沒沖的樣子∼。\n",
        "抓狂馬桶按鈕":"由於這裡實在太臭了∼你忍不住想按(push)下沖水(按鈕)。\n",
        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
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
        if (!arg || arg!="按鈕") return 0;
        message_vision(HIY"$N的頭突然被吸到馬桶裡,好豬ㄛ！。\n"NOR,me);
        me->move("/d/wiz/hall1");
        return 1;
}



