#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIC"�@���ɪ����\\"NOR,({"litre-tear ankle","ankle"}));
  set("long", @LONG  
�m�@���ɪ����\�n�H70�~�N��������ƭ���W�j�ά��G�ƭI���A
�@��15������T�֤k���èȤ]�A���n�i�}�H�ͤ������ꪺ����
�ͲP�C�J�ت��O�A�@���o�q���w�ƹL���ܤƧ��ܤF�o���@�͡A
�Ϧo���ͩR�b�u�u���Q�~���[�t��s�K�K
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("material","gold");
  }

    set("not_clone",1);
  set("armor_prop/int",1 );
  set("armor_prop/str",1  );
  set("armor_prop/dex",1  );
  set("armor_prop/con",1  );
  set("armor_prop/armor", 3 );
  set("armor_prop/shield", 3 );
  set("armor_prop/show_damage", 1);
  setup();
}
