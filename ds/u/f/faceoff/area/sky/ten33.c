#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�a�ſ���"NOR);
 set("long",@LONG
�A���W�F�������W, �o�o�{�W���{�p�j����Z����g��, 
�ӥB�A�����U�l�׳��u���@���ʦp��ê�����, �@�Ӥ��p��
�N�|�L�U�U�V�`�W,�өγ\�O�]���o�̦a�ո���,�]���o�̬�
���H�N, �ө��n�h�O�^���s��p����....
LONG
    );
 set("exits",([  "north":__DIR__"ten34",
                 "southdown":__DIR__"ten32",
    ]));
set("no_map",1);
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
  object me;
  me =this_player();
  if( interactive(me = this_player()) && !me->is_fighting())
  {
  remove_call_out("hi");
  call_out("hi",1,me);
  }
}
void hi(object me)
{
        tell_object(me,CYN"�A���������h�F���ŷP....\n"NOR);
        call_out("cold",5,me);
        return;
}
void cold(object me)
{
if(!me || environment(me) != this_object()) return;
       tell_object(me,CYN"�A�P��A�����O�w�g�����������o�̪��ŴH�F...\n"NOR);
     me->receive_damage("ap",30);
     call_out("cold2",4,me);
     return;
}
void cold2(object me)
{
if(!me || environment(me) != this_object()) return;
     tell_object(me,CYN"�A�P�챡�ζV�ӶV�����F, �A�����κ����}�l�n��, ���\\�C�C�A���}�ӤF....\n"NOR);
     me->receive_damage("hp",250);
     call_out("cold3",4,me);
     return;
}
void cold3(object me)
{
if(!me || environment(me) != this_object()) return;
    tell_object(me,CYN"�A�C�C���V���ɱ�, �ש�L�k�J��V�U�P�h !!\n"NOR);
    message_vision(CYN"$N�G�s�ۺL�U�A�}�U���L���`�W!\n"NOR,me);
     me->receive_damage("hp",230);
    me->move(__DIR__ "ten29");   
     return;
}


