#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
  set_name(HIC"�{�q�u"NOR,({"flash boots","boots"}) );
  set("long",@LONG
�o�����⪺�u�l���ѥO�H���H�ܩڪ��y�O�A�ä��ɪ��{�{�Xģ���q���C
LONG
);
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("unit", "��");
  }
  set("value",1380);
  set("armor_prop/dex",2);
  set("armor_prop/armor",12);
  set("armor_prop/dodge",10);
  setup();
}
