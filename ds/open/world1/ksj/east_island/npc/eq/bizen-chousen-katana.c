#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"備前長船"NOR, ({ "bizen-chousen katana","katana" }) );
  set("long",@long
結合眾多刀匠所合力打造，刀刃超過三尺，是把壯麗的長刀。此刀曾
經有許多有名的劍客使用過，歷經大小戰役，長久以來吸收劍氣及血
氣，是接近神刀的名刀。
long);      
  set_weight(3250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("material", "blacksteel");
    set("value", 9000);
    set("volume",5);
  }
  set("limit_lv",25);
  set("weapon_prop/str",2);
  set("weapon_prop/dex",2);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(60);
  set("wield_msg","$N拔出背後的$n，刀光漸漸延伸籠罩住$N。\n");
  set("unwield_msg","$N反轉刀刃，俐落地將$n收回背上的刀鞘。\n");
  setup();
}

