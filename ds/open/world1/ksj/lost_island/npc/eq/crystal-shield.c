#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIW"�����޵P"NOR,({"crystal shield","shield"}));
  set("long", @LONG
��w���ѵM�դ����s�����޵P�A���F�������Ȥ���A�󦳤��������@
�O�A�O�j�N�����]�k�v�һs�@���öQ����C
LONG);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",80000);
    set("material","stone");
  }
  set("armor_prop/armor",20);
  set("armor_prop/shield",25);
  set("armor_prop/int",1);
  setup();
}
