#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "�Ѿ���");
  set ("long", @LONG
�j�Ӧ��a���s�A���իF�O�A��H�´ˡA�̦a�զӫءA�I�a�s�^�D
�c�Ѿ����C�j�ӥD�����q�ѻڡA�q�X��s�c���W�A�ϥj�ӥD���Ѿ���
������ӹӦa�A���O�H�ʫ䤣�o��Ѫ��O�A�o�y�s�۷�ê����A�K
�Q�Q���]�O�j���i��A�o�S�p���b���a�إX�p�������ؿv�H
LONG
);
  set("exits", ([
  "north" : __DIR__"room90",
  "south" : __DIR__"room88",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
//  replace_program(ROOM);
}

// 2003.4.10 �s�W���ץ\�� by ksj
int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("red-eye black dragon", this_object())) && dir == "north" && userp(me))
  {
    message_vision(HIW"��$N�չϱq$n"HIW"�����ǳq�L�ɡA�Q$n"HIW"�������פF�^�ӡI�I\n"NOR,me,guard);
    write(HIG"[�ݨӥ��ݥ��˨e�F�A�_�h�O�Q�q�L�o��]\n"NOR);
    if(!random(4))
    {
      message_vision(HIR"$N�j�q�@�n�A��������������j���A�������µ�$n���Y�N�O�@���I�I\n"NOR,guard,me);
      guard->kill_ob(me);
    }
    return notify_fail("");
  }
  return ::valid_leave(me, dir);
}
