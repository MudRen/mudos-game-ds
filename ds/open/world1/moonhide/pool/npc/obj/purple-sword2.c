#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name("���שw���C" NOR ,({"perple-light sword","sword"}));
  set("long","���שw���C�A�D�j�^���ܹFù�P����E�ԫᤧ�򪫡A����O�򪫡A�i�Q�Ӫ��C\n");
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",6000);
   }
   set("limit_str",28);
   set("limit_dex",30);
   set("material","gold");
   set("weapon_prop/hit",5);
   set("weapon_prop/int",-1);
   set("weapon_prop/str",2);
   init_sword(45);
   setup();
}
