#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�P������"NOR);
 set("long",@LONG
�A���G�L�F�����A��J�F�o�ө_�Ǫ��a��A�Pı�W�|�P
���O�@�ǵ�L���·t�A�o�S���G�|�P���R���F�ͩR���߰ʡA
����A���A�G�Ū����~�b�A���e�観�ͩR���߰ʵ�....
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
        tell_object(me,HIW"�A���@�ئV�e�檺�Pı.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"�A�V�ӶV����e�誺���ǥ��~�F...\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "�U���F�ۧ���$N�ɡA$N���W������I�N�F�U���F�۪�Ĳ��...!!�C\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "�U���F�۪�����H��Ĳ��H�p�^�U�v���ձ��V$N.....!�C\n"NOR,me);
             me->receive_damage("hp",1000);
            }
     call_out("cold3",2,me);
     return;
}


void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"�A���_�i���J�F���ǫ߰ʪ����~�A�K�ɶ����h�F��ı....\n"NOR);
     call_out("cold4",3,me);
     return;
}

void cold4(object me)
{
if(!me || environment(me) != this_object()) return;
    me->move(__DIR__ "ten48");   
     return;
}

