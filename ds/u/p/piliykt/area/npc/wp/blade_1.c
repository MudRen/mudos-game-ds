#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
  set_name(HIB"�[���M"NOR, ({ "look sky blade","blade" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O���K��һs�����j�M�A�O�@����H�W�����_�M�C\n");
    set("material", "steel");
    set("value",2200);
    set("volume",5);
  }
          set("limit_dex",25);
          set("weapon_prop/con",1);
          set("weapon_prop/dex",1);
  init_blade(35);
  setup();
}


