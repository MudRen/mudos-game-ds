#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
 set_name("發光帶", ({ "light cycle","cycle" }) );
 set_weight(100);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("long","很輕的一條發光體, 不知道穿在哪裡。\n");
  set("unit", "條");
  set("material", "cloth");
//set("no_drop",1);
  set("no_sac",1);
  set("value",5000);
  set("armor_prop/armor",1);
 }
   set_temp("has_light",1);
        setup();
}

int query_autoload()
{
 return 1;
}
