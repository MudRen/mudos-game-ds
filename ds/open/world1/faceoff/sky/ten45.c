#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�t�D"NOR);
 set("long",@LONG
�A���@�ө_�Ǫ��Pı�A�A�w�g���b�Х@�����F�A�o�̬O
�@�Ӥp�p����ǡA�|�P������W���O���w�A�o�Ӥ�Ǥ�����
�ͪ��ݨӹ�A���S�����򵽷N.....
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
        tell_object(me,HIW"�A���M���@�ئb���ʪ��_���Pı.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"�A�P��@�}�_�Ǫ����t�A���۸T�����W�F����....\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "�b�@�ǿs�����߽ù�$N�@�F���w�諸��աC\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "�·t���߽ê����x���M�@�Ѧ�{����ĦV$N....!�C\n"NOR,me);
             me->receive_damage("hp",100);
            }
     call_out("cold3",2,me);
     return;
}

void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"�A�����I�I�����G���ʨ�t�~�@�Ӧa��F�A�A�������i�}�F����....\n"NOR);
     call_out("cold4",3,me);
     return;

}

void cold4(object me)
{
if(!me || environment(me) != this_object()) return;
    me->move(__DIR__ "ten46");   
     return;
}
