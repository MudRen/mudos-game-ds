#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"����"NOR);
 set("long",@LONG
�@�i�}�����A���e�N�O�o�ө_�Ǫ������F�A�����D�O�Τ�
��@������A�ݤW�h���p�P�Ť@��A���G�O�@�ǸH�p�^�b�¥�
���W�A�ө��M�@�ة_�Ǫ��Pı�S�ӤF....
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
        tell_object(me,HIW"�A�S���@�ئb���ʪ��Pı.....\n"NOR);
        call_out("cold",3,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,HIW"�A�P��@�}�Y���دt�A���۸T�����W�F����....\n"NOR);
     call_out("cold2",2,me);
     return;
}

void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
             if(me->query_temp("bless") == 1)
           {
                        message_vision(HIG "�{���{�����Ѩͤ��z��$N��F���|�C§�C\n"NOR,me);
           }
           else
           {
                 message_vision(HIR "���M�@�}�{���{�L, $N��������G�Q�Ѩͤ��z�⤤���C�A��...!�C\n"NOR,me);
             me->receive_damage("hp",400);
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
    me->move(__DIR__ "ten47");   
     return;
}

