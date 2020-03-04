#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "�j����");
  set("long", @LONG
�o�̬O���Z�j���Ŭu����A��Ӿ���ϥΤ�O�f�ءA���䦳���d
�x�A�j�D�����O�����˪��Ŭu�A�������h�����ˤ�h�D�`���ġA�A
�i�H�b���P�߱��b�o�z�ɨ��w�����ֽ�(spa)�C
LONG
);
  set("exits", ([
      "out" : __DIR__"room17",
               ]));
  set("light", 1);
  set("no_fight", 1);
  set("no_cast", 1);
  set("no_exert", 1);
  set("no_clean_up", 0);
   set("objects",([
      __DIR__"npc/eq/bath-pool":1,
     ]) );
  setup();
}

void init()
{
  add_action("do_spa","spa");
}

int do_spa()
{
  object me;
  me=this_player();
  if( me->query_temp("bathe") <= 0 )
  {
    write("�A�ү�w�������Ƥw�Υ��F�I\n");
    return 1;
  }

  if(me->query_temp("is_busy/washing"))
  {
    write("�A���b�ΪA�a�w�����C\n");
    return 1;
  }
  message_vision(HIW "$N�ܧ֦a���W�F�D��A���F�d�~�Ψ㩹�j�D�����F�L�h�C\n\n" NOR, me);
  tell_object(me, HIW "�A�C�C�a���i�D�����F�U�h�A�I���u�O�ΪA���C\n\n" NOR );
  tell_object(me, HIB "�A�N��y��n�л\\�b�Y�W�A���������������P�a�b���ۡC\n\n\n" NOR );
  me->disable_player_cmds("�A���b�ΪA�a�w���C\n");
  me->set_temp("is_busy/washing","�A���b�ΪA�a�w���C");
  me->start_busy(10);
  call_out("wash1",3,me);
  call_out("wash2",8,me);
  call_out("wakeup",15,me);
  return 1;
}

void wash1(object me)
{
  if(!me) return;
  tell_object(me,HIG"�A�uı�o���߲@�L�t��A�ϩ��i�J�L�~�L�{���@�ɡ�\n"NOR);
  me->receive_heal("hp",me->query_con()*4);
  me->receive_heal("ap",me->query_con()*2);
  me->receive_heal("mp",me->query_int()*3);
  return;
}

void wash2(object me)
{
  if(!me) return;
  switch( random(4))
  {
     case 0:
          tell_object(me,HIG"�A�����e�B�{�F�@�����A���W�s�����R�A�L���j�ء��\n"NOR);
          break;
     case 1:
          tell_object(me,HIW"�A�����e�X�{�F�\\�h���L�Q���A�A�����a�@�@���_�Ӵ��R���\n"NOR);
          break;
     case 2:
          tell_object(me,HIM"�A�����e�B�{�F���j�Ѫ��K�ǡA�K�Ǫ��|�P���M�����O�Z�L���ǡ��\n"NOR);
          break;
     case 3:
          tell_object(me,HIY"�A�����e�B�{�F�@�y���ѽ��ת��c���A�A�����b���y�W�����s�ڪ��«����\n"NOR);
          break;
  }
  me->receive_heal("hp",me->query_con()*5);
  return;
}

void wakeup(object me)
{
  if(!me) return;
  message_vision(HIW"$N��M�Q���䪺�ȤH�I�F�@�U�A�|�F�|�������F�L�ӡC\n" NOR,me);
  me->enable_player_cmds();
  me->delete_temp("is_busy/washing");
  me->receive_heal("hp",me->query_con()*7);
  me->receive_heal("mp",me->query_int()*3);
  me->receive_heal("ap",me->query_con()*3);
  me->add_temp("bathe",-1);
  return;
}
