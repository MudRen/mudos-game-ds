#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIR"��ô�¤j�Z"NOR ,({ "red armor","armor" }) );
  set("long",@LONG
�@��˹����R�A�Q��Q�������Z�A���K��������s���A���U���m�O�P
���K�ʡA��H�W�Q���˹��A�ä��O�@��H������۪��C
LONG);
  set_weight(6000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",12000);
  }
  set("limit_con",40);
  set("limit_lv",30);
  set("armor_prop/armor",28);
  set("armor_prop/bar",1);
  set("armor_prop/tec",-1);
  set("armor_prop/dex",-1);
  setup();
}
