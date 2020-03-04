#include <armor.h>
#include <ansi.h>
inherit HEAD;

string *wounds = ({
  "head", 
  "body",
  "right_arm",
  "left_arm",
  "right_leg",
  "left_leg",
});

void create()
{
  set_name(HIW"�f��"HIR"�s��"NOR,({ "inverse-horn helmet","helmet" }) );
  set("long",@LONG
    �����D�岴�f���c�s���Y���A���O�W�j���������M���o���K���
�A�A�@��V�e�f���U�Q�Q�����H�����j�������P�A�Y�����ۤ��٤���
�����{���w�������C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(7000);
    set("unit", "��");
    set("value",15000);
    set("volume",5);
    set("light",1);
  }
  set("armor_prop/armor", 15);
  set("armor_prop/shield",10);
  set("limit_con",50);
  set("limit_str",20);
// 2003.3.30 �s�W lv���� by ksj
  set("limit_lv",43);
  set("armor_prop/con", 2);
  set("armor_prop/str", 2);
  set("armor_prop/dex", -1);
  call_out("receive_by_helmet", 30);
  setup();
}

void receive_by_helmet()
{
  object me = environment(this_object());
  int p_ap, i;
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/head")==this_object() )
  {
    p_ap = me->query("max_ap");
    if( me->query("ap") < p_ap*4/5 )
    {
      me->receive_heal("ap", p_ap*1/100);
      for(i=0;i<sizeof(wounds);i++)
      me->receive_curing(wounds[i], 1);
      message_vision(HIR"$N�����ۤ������j���A�@�}�`�����Pı�Ǩ�$n���餺....\n"NOR, this_object(), me);
    }
    else
    {
      tell_object(me,HIW"�f��"HIR"�s��"NOR"�o�X������~�A���O�S������Ƶo�͡I\n");
    }
  }
  call_out("receive_by_helmet", 35);
}
