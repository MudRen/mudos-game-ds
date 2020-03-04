#include <ansi.h>
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



inherit ROOM;
void show(object me);
void create()
{
        set("short",HIR"抓狂之門"NOR);
        set("long",@LONG
這裡是sexking的家門口，據說sexking是一個很抓
狂的人，所以叫作抓狂之門，不過sexking為了怕
也有許多人抓狂所以設了機關讓人無法進來。
LONG
);

        set("item_desc",([
        "抓狂電鈴":"這是一個很可愛的電鈴，讓你忍不住想按(push)看看。\n",
        "抓狂之門":"這是一個很好笑的門，不知為什麼你看了就覺得好好笑，忍不住想碰(touch)看看。\n",
        ]) );
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_push","push");
}

int do_touch(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="抓狂之門") return 0;
     message_vision(HIR"$N抓狂的摸了一下門，突然抓狂之門張大了嘴巴將$N吸了進去。\n"NOR,me);
     me->delete_temp("the-door");
     me->move(__DIR__"door");
        me->start_busy(4);
        call_out("flop1",3,me);
        return 1;        
}

void flop1(object me)
{
        if(!me) return;
if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIM"你突然從抓狂之門滾了出來，十分狼狽的樣子。\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"突然從抓狂之門滾了出來，十分狼狽的樣子。\n"NOR,me);
        return;
}
int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="抓狂電鈴") return 0;
     message_vision(HIG"$N抓狂的按了一下抓狂電鈴，突然冒出了一沱小麥草黏液將你$N包了起來將$N甩到了天上。\n"NOR,me);
     me->delete_temp("the-sky");
     me->move(__DIR__"sky");
        me->start_busy(4);
        call_out("flop2",3,me);
        return 1;        
}
void flop2(object me)
{
        if(!me) return;
if (me->query_temp("fly-sky")==1) return 0;

        tell_object(me,HIC"你重重的摔到地上，跌個四腳朝天，屁股腫了一大塊起來。\n");
        me->move(__DIR__"workroom2");
        tell_room(environment(me),me->query("name")+"重重的摔到地上，跌個四腳朝天，屁股腫了一大塊起來。\n"NOR,me);
        return;
}
