#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIG"����Y�a"NOR ,({ "brambly crown","crown" }) );
  set("long",@LONG
�@���ѯ����s���Y�a�A�Y�a�W�}�۴X���_�ΩǪ�������p��A�J��
�@�ݼƤ��ɪ��y��W���M�٪��ۦp�����몺�ˤġA�u�L�k�Q�������
���H�|�h���o�Y�a�C
LONG
);
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",1);
  set("armor_prop/dex",-2);
  set("armor_prop/bio",-1);
  set("armor_prop/int",2);
  set("armor_prop/wit",1);
  set("wear_msg",
      "$N�Եۯk�h�N�@�������y��$n���b�Y�W�A�����z�X��w�Ӧ��O�������C\n"NOR);
  setup();
  call_out("blooding_by_crown", 30);
}

void blooding_by_crown()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return;
  if( me->query_temp("armor/head")==this_object() )
  {
    me->receive_damage("hp", 5+random(10));
    message_vision(RED"$N�W���y�봡�J$n���֦סA�X�w�A��q$n���B�Y�W�y�F�U��....\n"NOR, this_object(), me);
  }
  call_out("blooding_by_crown", 35);
}
