#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIW"�]�N�v��M"NOR,({"mage gloves","gloves"}) );
        set("long",@long
�]�N�v��������M�A�Z�n�ݪ��C
long
);
        set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
                set("volume",3);
                set("unit","��");
                set("value",10000);
  }
                set("limit_lv",50);
                 set("armor_prop/str",3);
                set("armor_prop/armor",10);
                set("armor_prop/show_damage",1);
  setup();
}
int query_autoload() { return 1; }
