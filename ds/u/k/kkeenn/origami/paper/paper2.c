#include <ansi.h>
#include <armor.h>
inherit CLOTH;
int check(object me);
void create()
{
  set_name("Ｄ頭摺紙", ({ "none paper", "paper" }) );
  set("long", " 
    這是一張已被折成招換精靈摺紙鎧甲的化身摺紙。
"HIG"化身：change xxx"NOR"
xxx 等於您的化身精靈名稱，請小心使用，避免獸化。
"NOR);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");
    set("long", " 
"NOR);
    set("value",0);
    set("no_drop",1);
    set("no_sell",1);
    set("no_get",1);
    set("no_sac",1);
    set("no_give",1);
  }
   setup();
}
int query_autoload() { return 1; }
void init()
{ 
    object me= this_player();
    add_action("do_change", "change");
    if( !me ) return;
    if( !userp(me) ) return;
    check(me);
}
int check(object me)
{
  object ob = this_object();
if(me->query("family/name"))
   { 
this_object()->set_name(me->query("family/color")+"的"+me->query("family/name")+"摺紙", ({me->query("family/id")+" paper", "paper" }) );
  }  
  add_action("do_wear","change");
  add_action("do_nowear","wear");
}
int do_wear(string arg) 
{
object obj,me;
int i = this_player()->query("max_ap") / 100 * this_player()->query("family/level");obj = this_object();
me  = this_player();
if(!arg) return notify_fail("你想化身成...？\n"); 
if( arg != me->query("family/id")) return notify_fail("你不能化身成為"+ arg +"啦！\n"); 
if(me->query_temp("change")) return notify_fail("你已經在化身狀態了！\n");
message_vision(HIG"$N大喝一聲：招換化身鎧甲 - "HIW+me->query("family/color")+me->query("family/name")+HIG" - ！\n"NOR,me);
if( environment(obj) == me )
  {
obj->set_name(me->query("family/color")+me->query("family/name")+"鎧",({"armor"}));
obj->set("armor_prop/name", ({ me->query("family/color")+me->query("family/name") }) );
obj->set("armor_prop/armor",me->query("family/level") * 3);
call_out("back",i,me,obj);
  }
obj->set("long", "這是一件精靈鎧甲。"NOR);
me->set_temp("change",1);
obj->wear();
 return 1;
}
void back(object me,object obj)
{
obj = this_object();
me  = this_player();
write(HIW"微電腦告訴你：Beep！你的化身能源已經用盡！\n"NOR);
obj->unequip();
obj->set_name(me->query("family/color")+"的"+me->query("family/name")+"摺紙", ({me->query("family/id")+" paper", "paper" }) );
obj->delete("armor_prop/name");
me->delete_temp("change");
obj->set("long", " 
    這是一張已被折成招換精靈摺紙鎧甲的化身摺紙。
"HIG"化身：change xxx"NOR"
xxx 等於您的化身精靈名稱，請小心使用，避免獸化。
"NOR);
message_vision(HIG"$N的化身能源用盡，變回普通人了。\n"NOR,me);
return;
}
int do_nowear(string arg) 
{
object me;
me  = this_player();
if(arg == "paper" || arg == me->query("family/id")+" paper" || arg == "all")
 {
  if(!me->query_temp("change")) 
   {
   write("這件裝備損壞了，並不能裝備\n");
   return 1;
   }
 }
}

