#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
  set_name("�V�����U",({ "captain's hat","hat"}) );
  set("long",@LONG
�@������M�Ϊ��U�l�A�W���g���������C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(700);
    set("unit", "��");
    set("value",500);
    set("volume",1);
  }
  set("armor_prop/armor", 3);
  setup();
}
