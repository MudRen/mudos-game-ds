#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIG"八方子舞鞭"NOR , ({ "dance whip","whip" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "條");
    set("long", "古老以前的舞者，在八方靈洞裡日夜鑽研，所打造的上古神兵。\n");
    set("material", "sliver");
    set("value",1000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
  }
        set("wield_msg",HIM"$N以極為華麗的手腕，拿起此鞭之後緩緩的甩動。\n"NOR);
        set("unwield_msg", HIC"$N放下此鞭後，附著在鞭上的華麗之氣息消失殆盡。\n"NOR);
  init_whip(77);
  setup();
}

