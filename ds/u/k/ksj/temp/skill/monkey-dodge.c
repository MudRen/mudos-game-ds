#include <ansi.h>
inherit SKILL;

void remove_add_dodge(object me);

string *dodge_msg = ({
        HIM"$n��ı$N����աA�ߧY�}�����D��@�ǡA�{�L$N�������C\n"NOR,
        HIM"$n����D�_�A�b�Ť��@��½��A���a�ɤw�b$N����C\n"NOR,
        HIM"$n�������k�X���۸��A�k���F$N�ۦ����d��C"NOR,
        HIM"$n�k���a�@��½�u�A�I�I���L$N�������C\n"NOR,
        HIM"$n���Τ��ʡA�V�����ƨB�A�ϱo$N���ۦ����šC\n"NOR,
});

int exert(object me, object target, string arg)
{
  int tmp;
  if ( arg=="off" )
  {
    if( me->query_skill_mapped("dodge")!="monkey-dodge")
      return notify_fail("�A�èS���ϥη᭸���N�C\n");
    me->map_skill("dodge");
    me->reset_action();
    message_vision("\n"HIW"$N�S��_�^��Ӫ��t�פF�C\n"NOR,me);
    remove_add_dodge(me);
    write("�����ϥΧޯ� - �{�פ��޷᭸���N�C\n");
    return 1;
  }
  if( me->query_skill("dodge") < 5 )
    return notify_fail("�A�����\\��¦�����L�k�ϥη᭸���N�C\n");
  if( !me->skill_active("monkey-dodge", (: call_other, __FILE__, "delay", me :), 12) )
    return notify_fail("�A���b�ϥη᭸���N�C\n");
  if( me->query("ap") < 10 )
    return notify_fail("�A������ثe���p�ٵL�k�ϥη᭸���N�C\n");
  me->map_skill("dodge","monkey-dodge");
  me->reset_action();
  message_vision("\n"HIB"$N���[�K���A�νw�����A�}�l�ϥη᭸���N�C\n"NOR,me);
  me->receive_damage("ap", 1);
  me->start_busy(1);
  if( me->query_temp("class_blade/monkey-dodge") )
    remove_add_dodge(me);
  me->add_temp("apply/sk_dodge", (tmp = me->query_skill("monkey-dodge",1)*2/5 + me->query_skill("dodge", 1)/5 + random(me->query_skill("dodge",1)/4)));
  me->set_temp("class_blade/monkey-dodge", tmp);
//      me->skill_active("fogseven", (: call_other, __FILE__, "delay", me :), 12);
  return 1;
}

void delay(object me)
{
  if( !me ) return;
  if( me->query_skill_mapped("dodge")!="monkey-dodge" )
  {
    remove_call_out("delay");
    remove_add_dodge(me);
    return;
  }

  if( me->query("ap")<10 )
  {
    me->map_skill("dodge");
    me->reset_action();
    message_vision("\n"HIW"$N�S�^�_��F�@�몺�t�סC\n"NOR,me);
    tell_object(me,"�A�������w�áA�w�L�k�A�ϥη᭸���N�C\n");
    remove_add_dodge(me);
    remove_call_out("delay");
    return ;
  }

  if( me->is_fighting()  )
  {
    if( (me->query_skill("monkey-dodge") + me->query_skill("dodge") - 30) > 1 ) me->receive_damage("ap", 1);
    else me->receive_damage("ap", 2);
  }
  me->skill_active("monkey-dodge",(: call_other, __FILE__, "delay", me :), 10);
}

void remove_add_dodge(object me)
{
  int ar1 = (int)me->query_temp("class_blade/monkey-dodge");

  if( ar1 < 0 ) return;
  me->add_temp("apply/sk_dodge", -ar1);

  me->delete_temp("class_blade/monkey-dodge");
  return; 
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me) { return 1; }
int improve_limite(object ob) { return 100; }
int valid_learn(object me) { return 1; }
