#include <armor.h>
inherit MASK;
void create()
{
  set_name("�ȭ���" ,({ "paper mask","mask" }) );
  set("long","�o�O�@�Ӥp�Ĥl�ΨӹC�����ȭ���A�W���e���O�P�x���y�C");
  set_weight(100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "paper");
    set("volume",1);
    set("unit", "��");
    set("value",150);
  }
  set("armor_prop/armor",2);
  setup();
}
