#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
  set_name( RED "����ֿ�" NOR ,({ "leather pants","pants" }) );
  set("long",@long
  �@��`����ֻs�ǺޡA�ݰ_�ӹ����F��z�ǡC
long
);  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",2);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/armor",4);
  set("armor_prop/dex",1);
  set("armor_prop/shield",2);
  setup();
}

int query_autoload() { return 1; }

