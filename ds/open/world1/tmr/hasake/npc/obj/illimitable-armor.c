#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
   set_name(HIW"�D�a�B��"NOR ,({ "illimitable armor","armor" }) );
  set("long",@LONG
�D�a�B�ҬO�կT���Ҭ諸�ԥҡA�ϥΡu�D�a�ȦB�v���B���һs���A��
����K�A�㦳���������m�O�A�]�঳�Ħa��תk�N���ˮ`�C���@�W
�èS������u���i�H���y�X�o�ؾԥҡC
LONG);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",4);
    set("unit", "��");
    set("value",15000);
  }
  set("limit_lv", 40);
  set("armor_prop/armor", 45);
  set("armor_prop/shield",45);
  set("armor_prop/int", 1);
  set("armor_prop/con", 1);
  setup();
}

