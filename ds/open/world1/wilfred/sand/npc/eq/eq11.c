#include <armor.h>
inherit BOOTS;
void create()
{
  set_name("��j" ,({ "clogs","boots" }) );
  set("long","��s�D�c�A�~�[�򥭱`�����c�j�����A���_���ӷ|�سا@�T�C");
  set_weight(1300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "��");
    set("value",500);
  }
  set("armor_prop/armor",5);
  setup();
}