#include <armor.h>
inherit PANTS;
void create()
{
  set_name("�~��ֿ�" ,({ "beast pants","pants" }) );
  set("long","�o�~�ֿǦ�m����A��ӬO�Ѫ�֩һs�A��W�o�Ǥl���ͫ¡A���G�H�]���j�F�_�ӡC");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",1200);
  }
  set("armor_prop/armor",10);
  setup();
}