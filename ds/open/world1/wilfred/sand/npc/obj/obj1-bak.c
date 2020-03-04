#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

int hit;
int again, index;

void create()
{
  set_name(HIC"�s�����q"NOR,({"final book","book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",NOR""
WHT"�y�K���j�[-�̲צ��@�Y���������x��"HIW"(triple)"NOR""
WHT"�z�A�Ѷȼƭ��A���Y�e�ۤ@�ǹ��СC\n\n"
HIG"����: �z��(triple)3 �� �Ĥ@��(426p)5 �� �ĤG��(26264p)1 �� �ĤT��(466pk)\n"
"�Цۦ��ɶ���J\n\n"NOR);
    set("unit","��");
    set("value",10);
  }
  setup();
}

// �Ȯɥ� add_action ����k�Ӵ��ѿ�J�����O����
// �¨줣��A�ª���k    wilfred@DS
void init()
{
  add_action("do_super","",1);
}

int do_super()
{
  object me = this_player(), *enemy, weapon;

  hit = 0;
  if ( (string)query_verb() == "triple" )
  {
    weapon = me->query_temp("weapon");
    if(weapon && weapon->query("skill_type") != "unarmed")
      return notify_fail("�A��W���Z�����A�X�ϤK�����k�C\n");
    if( me->query_skill("horse-steps") < 95 ) return notify_fail("�A�K���ϰ�����¦�����A�L�k�z�o�X�������O�q�Өϥζ��q�C\n");
    if( me->query_skill("bagi_fist") < 80 ) return notify_fail("�A�K�����k����¦�����A�L�k�⮩���q�C\n");
    if(!me->is_fighting()) return notify_fail("�A���b�԰����I\n");
    if(me->is_busy()) return notify_fail("�A���b���C\n");

    message_vision("$N���S�@�n�A�N������l�U�I�ܴ�u�ޡA�ǳƨϥζ��q�Ĥ@���I\n",me);
    me->start_busy(1);
    hit = 1;
    call_out("hit_1",4,0);
    return 1;
  }
  if ( (string)query_verb() == "426p" )
  {
    if(index != 1) again = 0;
    if(again) return notify_fail("�ʧ@���ѡC\n");
    remove_call_out("hit_1");
    if(hit == 1) call_out("hit_1",5,1);
      else call_out("hit_1",1,0);
    index = 1;
    again++;
  }
  if ( (string)query_verb() == "26264p" )
  {
    if(index != 2) again = 0;
    if(again) return notify_fail("�ʧ@���ѡC\n");
    remove_call_out("hit_2");
    if(hit == 2) call_out("hit_2",3,1);
      else call_out("hit_1",1,0);
    index = 2;
    again++;
  }
  if ( (string)query_verb() == "466pk" )
  {
    if(index != 3) again = 0;
    if(again) return notify_fail("�ʧ@���ѡC\n");
    remove_call_out("hit_3");
    if(hit == 3) call_out("hit_3",1,1);
      else call_out("hit_1",1,0);
    index = 3;
    again++;
  }
  return 0;
}

void hit_1(int index)
{

  if(!index || this_player()->is_busy())
  {
    write("�ʧ@���ѡC\n");
    this_player()->start_busy(2);
    return;
  }
  
}

void hit_2(int index)
{
  if(!index || this_player()->is_busy())
  {
    write("�ʧ@���ѡC\n");
    this_player()->start_busy(2);
    return;
  }
}

void hit_3(int index)
{
  if(!index || this_player()->is_busy())
  {
    write("�ʧ@���ѡC\n");
    this_player()->start_busy(2);
    return;
  }
}
