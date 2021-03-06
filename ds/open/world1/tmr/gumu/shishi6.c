#include <ansi.h>
inherit ROOM;

void create()
{ 
        set("short",HIC"石室"NOR);
        set("long", @LONG
室中也無特異之處，你抬頭仰望，但見室頂密密麻麻的寫滿了字跡
符號，你看了一會，但覺奧妙難解。室頂西南角繪著一幅圖，似與武功
無關，凝神細看，倒像是幅地圖。石室右下方好像可以往下(down)走。
LONG    );
        set("item_desc", ([
                "down" : HIB"黑乎乎的，看不真切，你不能確定路到底要怎麼走(walk)。\n"NOR,
        ]));
        set("exits", ([
                "up" : __DIR__"shiguan",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_look", "look");
        add_action("do_walk", "walk");
}

int do_look(string arg)
{
        object me=this_player();

        if ( arg =="map")
        {
                write(HIY"你凝望著那幅圖，心中不由大喜，原來那繪的正是出墓的秘道。\n"NOR);
                me->set_temp("map", 1);
                return 1;
        }
         return notify_fail("你要看什麼？\n");
}

int do_walk(string arg)
{ 
        object me=this_player();

        if ( arg =="down")
        {
                if(!me->query_temp("map"))
                        return notify_fail("你伸腳想往下走，但是猶豫再三，又伸回了腳。\n");
                write(HIM"你東轉西彎，越走越低。同時腳下漸漸潮濕，暗中隱約望去，到處都是\n岔道。再走一會，道路奇陡，竟是筆直向下。下降了約莫半個時辰，這\n路漸平了，只是濕氣卻也漸重，到后來更聽到了淙淙水聲，路上水沒至\n踝。越走水越高，自腿而腹，漸與胸齊。\n"NOR);
                me->delete_temp("map");
                me->move(__DIR__"anhe1");
                return 1;
        }
        return notify_fail("你在石室里踱來踱去，不知如何是好？\n");
}

