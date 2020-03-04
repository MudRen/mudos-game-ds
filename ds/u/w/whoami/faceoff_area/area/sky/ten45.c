#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"暗道"NOR);
 set("long",@LONG
你有一個奇怪的感覺，你已經不在塵世之間了，這裡是
一個小小的方室，四周的牆壁上都是水滴，這個方室之中的
生物看來對你都沒有什麼善意.....
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
        tell_object(me,HIW"你忽然有一種在移動的奇妙感覺.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"你感到一陣奇怪的昏眩，不自禁的閉上了眼睛....\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "在一旁窺視的冥衛對$N作了個歡迎的手勢。\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "黑暗中冥衛的雙掌忽然一股血腥之氣衝向$N....!。\n"NOR,me);
             me->receive_damage("hp",100);
            }
     call_out("cold3",2,me);
     return;
}

void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"你昏昏沉沉的似乎移動到另外一個地方了，你漸漸的張開了眼睛....\n"NOR);
     call_out("cold4",3,me);
     return;

}

void cold4(object me)
{
if(!me || environment(me) != this_object()) return;
    me->move(__DIR__ "ten46");   
     return;
}
