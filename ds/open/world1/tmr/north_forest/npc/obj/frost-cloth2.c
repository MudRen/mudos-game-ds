#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name( "�B���֦�"  ,({ "frost-troll cloth","cloth" }) );
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
    set("armor_prop/int",1);
    set("armor_prop/dex",1);
    set("armor_prop/shield", 5);
    set("armor_prop/armor", 10);

  setup();
}


