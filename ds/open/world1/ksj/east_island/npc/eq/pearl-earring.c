#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIW"�ï]�չ�"NOR ,({ "pearl earring","earring" }) );
  set("long",@LONG
�¥լï]�������@��չ��A���Ȥ���C
LONG);
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("unit", "��");
    set("value",3500);
  }
  set("armor_prop/armor",1);
  setup();
}
