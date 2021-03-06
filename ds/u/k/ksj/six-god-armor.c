#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIW"六神鎧"NOR ,({ "six-god armor","armor" }) );
  set("long",@LONG
由奇倪、滅骨、霧獸外皮所組成的鎧甲。
LONG);
  set_weight(6000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",6);
    set("unit", "套");
    set("value",20000);
  }
  set("limit_con",50);
  set("limit_lv",35);
  set("armor_prop/armor",100);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/int",1);
  set("armor_prop/dex",1);
  set("armor_prop/bio",1);
  set("armor_prop/wit",-1);
  set("armor_prop/dodge",10);
  call_out("receive_by_armor", 30);
  setup();
}

void init()
{
  if( userp(environment(this_object()) ) )
  {
    add_action("do_wear", "wear");
  }
}

int do_wear(string arg)
{
  object me,eq1,eq2,eq3,eq4,eq5,eq6,eq7; 
  me = this_player();
  eq1= me->query_temp("armor/wrists");
  eq2= me->query_temp("armor/surcoat");
  eq3= me->query_temp("armor/boots");
  eq4= me->query_temp("armor/leggings");
  eq5= me->query_temp("armor/hands");
  eq6= me->query_temp("armor/waist");
  eq7= me->query_temp("armor/armor");
  me = this_player();
  if( eq1 ) return notify_fail("你穿著"+eq1->query("name")+"，無法再穿上六神鎧。\n");
  if( eq2 ) return notify_fail("你已穿著"+eq2->query("name")+"，無法再穿上六神鎧。\n");
  if( eq3 ) return notify_fail("你已穿著"+eq3->query("name")+"，無法再穿上六神鎧。\n");
  if( eq4 ) return notify_fail("你已穿著"+eq4->query("name")+"，無法再穿上六神鎧。\n");
  if( eq5 ) return notify_fail("你已穿著"+eq5->query("name")+"，無法再穿上六神鎧。\n");
  if( eq6 ) return notify_fail("你已穿著"+eq6->query("name")+"，無法再穿上六神鎧。\n");
  if( eq7 ) return notify_fail("你已穿著"+eq7->query("name")+"，無法再穿上六神鎧。\n");
  if( !this_object()->query("equipped") )
  {
    if( arg == "armor" || arg == "six-god armor" || arg == "all")
    {
      this_object()->wear();
      me->set_temp("armor/wrists",this_object());
      me->set_temp("armor/surcoat",this_object());
      me->set_temp("armor/boots",this_object());
      me->set_temp("armor/leggings",this_object());
      me->set_temp("armor/hands",this_object());
      me->set_temp("armor/waist",this_object());
      me->set_temp("armor/armor",this_object());
      return 1;
    }
  }
}
