#include <armor.h>
inherit PANTS;
void create()
{
  set_name("�j�s�W��u��" ,({ "bandits pants","pants" }) );
  set("long","�@��u�ǤW���ú��F��ڷ�ڪ���ˡA�ݨӤQ�����x�ȡA���L�`���j�s���߷R�C");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("volume",2);
    set("material", "leather");
    set("unit", "��");
    set("value",1200);
  }
  set("armor_prop/armor",15);
  setup();
}

