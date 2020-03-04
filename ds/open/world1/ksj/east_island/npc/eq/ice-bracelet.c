#include <path.h>
#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIW"�����N"NOR,({ "ice bracelet","bracelet" }) );
  set("long",HIW @LONG
�@�u���ժ����N�A�����o�X�ե��A�q���N�ǨӲM�D�J�ߦӤ��H�N���D
�N�A�A���ѱo�p�߫٫ٲ`�Ȥ��p�ߺL�a�F��(break)�C
LONG NOR);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(500);
    set("unit", "��");
    set("value",6000);
    set("volume",1);
    set("light",1);
  }
  set("armor_prop/armor", 2);
  set("armor_prop/shield",5);
  set("limit_con",20);
  set("limit_int",15);
  set("armor_prop/int", 2);
  if( !random(30) )
  {
    set_name(HIC"�����N"NOR,({ "ice bracelet","bracelet" }) );
    call_out("receive_by_bracelet", 30);
  }
  setup();
}

void init()
{
  add_action("break_bracelet","break");
}

int break_bracelet(string str)
{
  object me,env,ob,z,b;
  me=this_player();
  env=environment(me);
  ob=find_living("_NPC_KEN_");
  if(!me) return 0;
       
  if(str=="bracelet")
  {
    message_vision(
    HIW"\n$N�@���߮��_�����N���a�U�ΤO�@�{�A�y�ɳ����N�H�����L�Ư}��\n"NOR
    HIW"\n�A�P�ɩP�D�H��Q�H���l���Ʀ��ŷx���ե��A$N�b�ե����uı�o�{�p���͡I\n"NOR,me);
    me->receive_heal("hp",me->query("max_hp") - me->query("hp"));
    me->receive_heal("ap",me->query("max_ap") - me->query("ap"));
    me->receive_heal("mp",me->query("max_mp") - me->query("mp"));
    me->receive_curing("head", 50);
    me->receive_curing("body", 50);
    me->receive_curing("right_arm", 50);
    me->receive_curing("left_arm", 50);
    me->receive_curing("right_leg", 50);
    me->receive_curing("left_leg", 50);
    me->apply_condition("poison", 0);
    me->apply_condition("blooding", 0);

    if( objectp(z=present("warrior ice statue",env)) )
    {
      if( objectp(ob) )
      {
        if(!environment(ob) )
        {
          destruct(ob);
        }
        else
        {
          message_vision(HIW"\n�B�����쳷���N�ե��Ӯg���t�a�ĸѦ��@�y���C\n"NOR,me);
          destruct(z);
          destruct(this_object()); 
          return 1;
        }
      }
      message_vision(HIW"\n�B�����쳷���N�ե��Ӯg���t�a�ĸѡA�B�������Z�̤]�C�C�^�_���C\n"NOR
        HIC"\n�h�͡D�c�V$N�`�`�@���`�A�H�᩹�s������V�a�D�ӥh�C\n"NOR,me);
      message("world:world1:vision",
        HIR"\n\t�h�͡D�c�۹D�G�K�[�j�D�I����w�n�N�A�o�׮`���h�I�I\n\n"NOR
        ,users());
      b=new("open/world1/ksj/east_island/npc/ken.c");
      b->move("open/world1/ksj/east_island/room110.c");
      destruct(z);
    }
    destruct(this_object());
    return 1;
  }
}

void receive_by_bracelet()
{
  object me = environment(this_object());
  int p_mp;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/wrists")==this_object() )
  {
    p_mp = me->query("max_mp");
    if( me->query("mp") < p_mp*4/5 )
    {
      me->receive_heal("mp", p_mp*1/100);
      message_vision(HIW"�����N��M�o�X�@�D�ե��A�A�y�ɷPı���M��n�C\n"NOR, this_object(), me);
    }
  }
  call_out("receive_by_bracelet", 35);
}
