#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("���@" , ({ "kee whip","whip" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���H���\\�������@�l�C\n");
    set("material", "force");
    set("value",1000);
    set("weapon_prop/dex",1);
  }
  init_whip(10);
  setup();
}

int query_autoload() { return 1;} // save eq by alick
