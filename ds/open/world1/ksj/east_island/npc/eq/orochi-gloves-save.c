#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
   set_name(HIR"�u"HIW"�E"NOR"�K�["HIR"���"NOR,({"orochi gloves","gloves"}));
  set("long", @LONG
�K�[�j�D����ֻs������M�A��M�W�U�Q���f��W�[�ǳ\���ˮ`�O�C
LONG);
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",35);
  set("armor_prop/armor",13);
  set("armor_prop/shield",13);
  setup();
}

int query_autoload() { return 1; }
