#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"星門異界"NOR);
 set("long",@LONG
你似乎過了拱門，跨入了這個奇怪的地方，感覺上四周
都是一些虛無的黑暗，卻又似乎四周都充滿了生命的脈動，
紫色，橙色，亮藍的光芒在你的前方有生命的律動著....
LONG
    );
set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
  object me;
  me =this_player();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  me->start_busy(5);
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
        tell_object(me,HIW"你有一種向前行的感覺.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"你越來越接近前方的那些光芒了...\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "萬滅靈蠱攻擊$N時，$N身上的綠光焚燒了萬滅靈蠱的觸手...!!。\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "萬滅靈蠱的怒氣隨著觸手以雷霆萬鈞之勢掃向$N.....!。\n"NOR,me);
             me->receive_damage("hp",1000);
            }
     call_out("cold3",2,me);
     return;
}


void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"你鼓起勇氣跨入了那些律動的光芒，霎時間失去了知覺....\n"NOR);
     call_out("cold4",3,me);
     return;
}

void cold4(object me)
{
if(!me || environment(me) != this_object()) return;
    me->move(__DIR__ "ten48");   
     return;
}

