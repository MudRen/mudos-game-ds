#include <ansi.h>
inherit ROOM;

void create()
{
 set("short","遺跡");
        set("long",@LONG
這裡看起來十分乾淨，好像有人常常來打掃。遺跡的大門被人仔細的
用灰泥封住，看來是進不去了。大門上的匾額寫著摘星門，兩旁的石獅不
知道被什麼東西打到，缺了一大塊，沿著大門兩旁的牆角都長滿了野草，
似乎是刻意讓它長的，好像想把什麼痛苦的回憶遮掩起來一般。
LONG
        );
  set("item_desc",([
       "野草":"在角落的野草中好像有些什麼東西。\n",
       "石獅":"被打掉了一大塊，應該是被鐵鎚敲掉的。缺口的旁邊有暗紅色的痕跡，好像是血。
看起來是血先濺上石獅，再有人將被血濺上的那一塊拿走一般。\n",
       "大門":"被灰泥封住了，進不去。匾額上寫著摘星門，或\許\可以跟附近的人打聽打聽(inquiry)。\n",
                            ]));
        set("outdoors","land");
        setup();
 }
void init()
{
        add_action("do_search", "search");
        add_action("do_roll", "roll");
}
int do_search(string arg)
{
        object me;
        me=this_player();

        if (arg != "野草" )
                return 0;
        else 
        {
         message_vision( HIY "$N在野草中發現了一個小土堆，要挖(dig)嗎？\n\n" NOR ,me);
         add_action("do_dig","dig");
         return 1;
        }
}
int do_dig(string arg)
{
        object me;
        me=this_player();

        if(arg != "小土堆" && arg !="土堆") return 0;
        else 
        {
         message_vision(HIG"$N從土堆中挖出了一堆染血的石片。\n"NOR,me);  
         tell_object(me,HIB"你將這些石片拼湊起來，赫然發現上面凹了一塊，竟是手印的樣子！\n"NOR);
         tell_object(me,HIB"看來這手印的主人大有來歷，你\或\許\該\調查看看。\n"NOR);
         me->add_temp("quest/pick_star",1);
         message_vision(HIG"$N把石片重新埋回去。\n"NOR,me);
         return 1;
        }
}     
int do_roll(string arg)
{
        int t;
        object me;
        me=this_player();
        if(arg != "石獅") return 0;
        else{
        message_vision( HIG "$N轉動了石獅，突然腳下的地板打了開來！$N就這樣掉下去了！！\n\n" NOR ,me);
        me->start_busy(3);
        message_vision( HIG "$N整個人消失在洞中後，地板又無聲無息關上了，石獅也恢復了原狀。\n\n" NOR ,me);
        me->move(__DIR__"secret");
        return 1;
         
}
}