#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("�۪O�ݥ�",({ "stone corslet","corslet" }) );
  set("long",@LONG
������۪O��÷�l�s���b�@�_�A��b���W��n�@�e�@��A�ݰ_�ӻᬰ
�©�C
LONG);
  set_weight(4500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "��");
    set("value",0);
  }
  set("armor_prop/armor",15);
  set("armor_prop/dodge",-2);
  setup();
}
