#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW"�B���֦�"NOR ,({ "frost-troll cloth","cloth" }) );
  set("long",@LONG
�o�O�ѥ_��j�˪L���B�����]���o���֦�A�ȥժ����A�צp�u��
���B���@�˺}�G�C
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 20000);
    set("material", "fur");
  }
    set("limit_lv",40);
    set("armor_prop/str",1);
    set("armor_prop/int",2);
    set("armor_prop/dex",2);
    set("armor_prop/shield",10);
    set("armor_prop/armor", 20);

  setup();
}

