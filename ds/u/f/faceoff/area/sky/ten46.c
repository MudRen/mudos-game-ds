#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"拱門"NOR);
 set("long",@LONG
一張開眼睛，眼前就是這個奇怪的拱門了，不知道是用什
麼作為材質，看上去有如星空一般，似乎是一些碎鑽鑲在黑布
之上，而忽然一種奇怪的感覺又來了....
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
        tell_object(me,HIW"你又有一種在移動的感覺.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"你感到一陣頭昏目眩，不自禁的閉上了眼睛....\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "閃著爍光的天侍之魄對$N行了個舉劍禮。\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "忽然一陣爍光閃過, $N的形體似乎被天侍之魄手中的劍劈散...!。\n"NOR,me);
             me->receive_damage("hp",400);
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
    me->move(__DIR__ "ten47");   
     return;
}

