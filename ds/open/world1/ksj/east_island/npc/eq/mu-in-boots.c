#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(WHT"����"CYN"����"NOR, ({ "mu-in boots","boots" }) );
  set("long",@LONG
�@���]�p�S���֭��u�u�A�u�l�����˦���K�������A��N�l���쪺
�����]�o�����]��A�@�譱�W�[�u�O�A�@�譱�i�H�y�L�������ΡC
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","leather");
    set("value",2500);
    set("armor_prop/dex",1);
    set("armor_prop/dodge",5);
    set("armor_prop/armor", 6);
  }
  setup();
}
