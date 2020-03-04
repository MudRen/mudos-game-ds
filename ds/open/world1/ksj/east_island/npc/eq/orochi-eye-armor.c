#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(GRN"�D"HIR"��"GRN"�@��"NOR ,({ "orochi-eye armor","armor" }) );
  set("long",@LONG
�K���j�D�����y���P�@��A�b���w���ܦ���w���c�y�A�ҥH��Ө�
������q���K�������A�o���@�ҬO�j�D���Ჴ����n�}�H���i�H�Ψ�
��۷�@�@�Ҫ��Ϊ��A�q�`�j�D���Ჴ�y���O�N���N�O�ܦ��H���A��
��@�@�Ҫ���u�֤��S�֡C
LONG);
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "��");
    set("value",25000);
  }
  set("limit_con",50);
  set("limit_lv",40);
  set("armor_prop/armor",35);
  set("armor_prop/con",2);
  set("armor_prop/wit",1);
  set("armor_prop/bar",-1);
  set("armor_prop/dex",-3);
  set("armor_prop/dodge",-10);
  call_out("receive_by_eye", 30);
  setup();
}

void receive_by_eye()
{
  object me = environment(this_object());
  int p_ap,p_hp,p_mp,i,hl;
  hl=0;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/body")==this_object() )
  {
    p_hp = me->query("max_hp");
    p_ap = me->query("max_ap");
    p_mp = me->query("max_mp");

    if( me->query("hp") < (p_hp-200) )
    {
      me->receive_heal("hp", 150);
      hl = hl+1;
    }

    if( me->query("ap") < (p_ap-100) )
    {
      me->receive_heal("ap", 70);
      hl = hl+1;
    }

    if( me->query("mp") < (p_mp-100) )
    {
      me->receive_heal("hp", 70);
      hl = hl+1;
    }

    if(hl > 0)
    {
      message_vision(HIR"\n$N��M�l���P�򪺯�q�A�����a�e�{�G����A�@�ѱj�j���O�q\n"
           +"���������a�פJ$n���餤�C....\n"NOR, this_object(), me);
    }
  }
  call_out("receive_by_eye", 35);
}
