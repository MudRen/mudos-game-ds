#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "�ܤ���");
  set ("long", @LONG
�ܤ��������ؿv�����֤ߡA���k�O��Ӱ����A�U���@�����G�Q�V
�����Y�D�۳s�A��զp���䭸�X�����s�A�]���N��ӰƷ��A�H���Y�s
���H�Υk�Y�s�����W�A���e�@���`�s�A�޶i�¤Ѵ򪺤����A�����ѵM
���̻١C
LONG
);
  set("exits", ([
  "west" : __DIR__"room92",
  "east" : __DIR__"room91",
  "south" : __DIR__"room89",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
//  replace_program(ROOM);
}

// 2003.4.10 �s�W���ץ\�� by ksj
int valid_leave(object me, string arg)
{
  object guard;
  if(arg == "west" || arg == "east")
  {
    if( objectp(guard=present("blue-eye white dragon", this_object())) && userp(me))
    {
      if(!guard->visible(me))
        message_vision(HIW"��$N�����N�N���Q�q�����ǳq�L$n"HIW"�ɡA�o�Q$n"HIW"�Χ��ھצ�F�C\n"NOR,me,guard);
      else
        message_vision(HIW"��$N�չϱq$n"HIW"�����ǳq�L�ɡA�Q$n"HIW"�������פF�^�ӡI�I\n"NOR,me,guard);
      write(HIG"[�ݨӥ��ݥ��˨e�F�A�_�h�O�Q�q�L�o��]\n"NOR);
      if(!random(4))
      {
        message_vision(HIR"$N�j�q�@�n�A�C�⪺��������j���A�������µ�$n���Y�N�O�@���I�I\n"NOR,guard,me);
        guard->kill_ob(me);
      }
      return notify_fail("");
    }
  }
  return ::valid_leave(me, arg);
}
