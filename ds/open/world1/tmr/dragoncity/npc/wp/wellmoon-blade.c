#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name( HIY "井中月" NOR , ({ "well-moon blade", "blade" }) );
     set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long",@LONG
這把刀原本沒有名字，據傳是來自上古的神兵利器，綱質奇怪，
刀身會隱透黃芒，二百年前曾落入當時的第一刀法家『刀霸』凌上人
手上。後來凌上人攜刀退隱，此刀從此消聲匿跡，其後又輾轉落到蕭
銑手中，之後又轉送給寇仲，取名為「井中月」。
LONG);
    set("material", "gold");
    set("value", 15000);
    set("volume",1);
    set("replica_ob",__DIR__"steel-blade");
  }
        set("limit_str", 40);
        set("limit_con", 40);
        set("limit_level", 35);

    set("weapon_prop/str",2);
    set("weapon_prop/con",2);
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_blade(85);
  setup();
}

