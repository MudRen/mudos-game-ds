#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIG"�R���@"NOR , ({ "ru chu whip","whip" }) );
  set_weight(2700);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���X�n�ܷ����@�l�C\n");
    set("material", "silver");
    set("value",4500);
    set("weapon_prop/con",1);
    set("weapon_prop/dex",2);
  }
  init_whip(30);
  setup();
}

