#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short","無砂港內");
        set("long",@LONG
這裡已經是無砂港內了, 你可以發現往北的都是一些外國
人, 可見北邊的港道都是通往較遠的西方船泊處, 而往南邊的港
道則是通往像扶桑般較近的國家, 你發現這裡的海水極為清澈, 
令人有跳下去的衝動....
LONG
    );
        set("exits",([ "south":__DIR__"seacoun41",
  "west":__DIR__"seacoun37",
]));
        set("item_desc",([
  "海水" : "你可以看見有魚類在裡面游動, 如果你覺得泳技不錯, 應該可以跳(jump in)下去抓魚...\n",
]));
        set("no_clean_up",0);
        set("outdoors","land");
        setup();
}            

void init()
{
        add_action("typejump","jump");
}

int typejump(string arg)
{
        object me;
        me = this_player();
        if( arg != "in 海水" ) return 0;

        if( me->query_temp("ride") )
                write("看來你的座騎似乎不想跟你一起跳下去喔！\n");
        else if( me->query_skill("swim") > 10)
        {
                message_vision(CYN"$N 深吸一口氣, 縱身躍入海中!!\n"NOR,me);
                me->move(__DIR__"map_4_5");
        }
        else message_vision(HIB"$N不知死活, 縱身躍入海中, 幸虧岸上漢子趕來, 否則一條小命大概也沒了....\n"NOR,me);       
        return 1;
}

