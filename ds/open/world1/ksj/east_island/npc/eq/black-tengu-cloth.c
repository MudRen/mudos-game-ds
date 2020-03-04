#include <armor.h>
#include <ansi2.h>
inherit CLOTH;

void create()
{
  set_name(HBK"�Ѫ��˧�"NOR ,({ "black tengu cloth","cloth" }) );
  set("long",@LONG
�@��`�¦⪺�ǲ��A�ˡA���I���M�A���h�[�F�\�h�_�Ǫ������A����
�����]�O�\�h����V�����C
LONG);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",2000);
    set("material", "silk");
    set("armor_prop/shield",10);
    set("armor_prop/int",1);
    set("armor_prop/armor", 10);
  }
  call_out("receive_by_cloth", 30);
  setup();
}

void receive_by_cloth()
{
  object me = environment(this_object());
  int p_hp, i;
  if( !this_object() || !me ) return;
  if( me->query("id") != "black tengu" ) return;
  if( me->query_temp("armor/cloth")==this_object() )
  {
    p_hp = me->query("max_hp");
    if( me->query("hp") < p_hp-200 )
    {
      me->receive_heal("hp", 150);
    }
  }
  call_out("receive_by_cloth", 35);
}
