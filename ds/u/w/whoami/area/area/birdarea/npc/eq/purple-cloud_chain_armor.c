#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(MAG"�������"NOR,({"purple-cloud chain armor","armor"}));
  set("long", @LONG
�o�O�@��ε������@�����@�ҡA�o�Ǥ����b��������g�U�|���o
�X�իժ������E�o���Z�Ҥ]�O�����J�ˤ⥴�y���@��A��~�P�E
���@�Ԫ��ɭԥL�N�O��۳o��ԥҡE
LONG);
  set_weight(40000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",8);
    set("value",9000);
    set("material","mental");
  }
  set("limit_lv",35); 
  set("limit_str",30); 
  set("limit_con",50); 
  set("armor_prop/show_damage",1);
  set("armor_prop/armor",42);
  set("armor_prop/shield",31); 
  set("armor_prop/dex",-3);
  set("armor_prop/con",2); 
  set("armor_prop/int",2);
  setup();
}

