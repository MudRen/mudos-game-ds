#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(YEL"�R�ߥҫ`"NOR,({"huge-turtle armor","armor"}));
  set("long", @LONG
���R���ߥһs�����ҫ`�A��w�I���A���W�s�����@�O�C
LONG
);
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",5);
    set("value",8000);
    set("material","fur");
  }
// 2003.3.30 �s�W lv���� by ksj
  set("limit_lv",35);
  set("armor_prop/armor",45);
  set("armor_prop/dodge",-10);
  set("armor_prop/con",3);
  set("armor_prop/str",2);
  set("armor_prop/int",-2);
  set("armor_prop/dex",-4);
  setup();
}
