#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
    set_name(HIR"�u"HIW"�E"NOR"�K�["HBK"���"NOR,({"orochi shield","shield"}));
  set("long", @LONG
�K�[�j�D���B�Y�W���@������s�����޵P�A�����Ʀӱa���ȥ��A��
���K�ٰ�w�A�����q�۷��C
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",40);
  set("armor_prop/armor",27);
  set("armor_prop/shield",19);
  setup();
}

int query_autoload() { return 1; }
