#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name("������M",({"silk gloves","gloves"}));
  set("long", @LONG 
�o�O�@���������´������M�A��a�D�`�����X�C
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("value", 3000);
    set("material","silk");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 14);
  set("armor_prop/shield",10); 
  set("armor_prop/dex", 1);
  setup();
}

