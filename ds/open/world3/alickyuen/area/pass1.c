#include <ansi.h>
//updated 26/12
inherit ROOM;

void create()
{
        set("short", HIC"ST。Building＠E&O"NOR);
        set("long", @LONG
看見很多人在排隊，你才發現這裡是Saint的出入境大樓，有很多人在
排隊過關，看來他們是想回鄉探親的。同時也有很多商人帶著一包包大大
小小的貸物來賣，可想而知Saint是一個熱鬧的城市。
LONG    );
        setup();
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"train.c",
  "north":__DIR__"dst17.c",
]));
        set("light",1);
}

void init()
{
        add_action("do_show","show");
}

int valid_leave(object me, string dir)
{
        if( dir == "south" )
        {
                if (!me->query_temp("pass_enter"))
                        message_vision("大閘突然放下把$N攔了下來，突然廣播系統響起：「沒有通行證的，誰都不可以出去！」\n",me);
                else 
                {
                        message_vision("在旁的機械人說道：「請進請進！！」\n",me);
                        me->set_temp("pass_enter",0);
                        return 1;
                }               
        }
        return ::valid_leave(me, dir);
}

int do_show(string arg)
{
        object who;
        who=this_player();
        if( !objectp(present("passport", who)) ) return 0;
        if(arg != "通行證" && arg !="passport" ) return 0;
        message_vision("$N從袋子裡拿出你的公民證照給機械人們檢查。\n",who);
        if (who->query_temp("pass_enter")) return 1;
        who->set_temp("pass_enter",1);
        message_vision("機械人仔細地看了看$N手上的公民證照，說道：「這位$N並不是偷渡客,請進。」\n",who);
        return 1;
}

