#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(HIR"���b"NOR , ({ "shrimp blade","blade" }) ); 
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�����v���y�Ӧ����C\n");
    set("material", "sliver");
    set("value",1000);
  }
  set("weapon_prop/str",1);
  set("weapon_prop/block",5);
  init_blade(40); 
  setup();
}

