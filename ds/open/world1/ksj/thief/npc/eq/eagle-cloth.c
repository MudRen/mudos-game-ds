#include <ansi2.h>
#include <armor.h>
inherit CLOTH;

void create()
{
  set_name(HBK"���N�֦�"NOR,({"eagle clothes","clothes"}) );
  set("long",@LONG
�o�O�@��p�����֦�A�W����F�@�����j�����N�лx�A�ݮݦp�͡C
LONG
);
  set_weight(5100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("unit", "��");
  }
  set("auto_set",2);
  set("armor_prop/armor",18);
  set("armor_prop/shield",7);
  set("armor_prop/dex",1);
  set("armor_prop/int",-1);
  setup();
}
