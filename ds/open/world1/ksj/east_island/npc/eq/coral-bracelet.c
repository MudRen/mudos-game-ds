#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIM"����"NOR"����"NOR,({ "coral bracelet","bracelet" }) );
  set("long",HIW @LONG
�����⪺�}�G����i�������Ϊ��A���b��W�Pı�߱��ܴr�֡C
LONG NOR);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(700);
    set("unit", "��");
    set("value",800);
    set("volume",1);
  }
  set("armor_prop/armor", 1);
  set("limit_con",10);
  set("armor_prop/con", 1);
  set("armor_prop/int", 1);
  setup();
}
