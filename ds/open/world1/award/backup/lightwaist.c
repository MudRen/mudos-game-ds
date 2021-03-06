#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
 set_name("螢光索",({ "light rope","rope" }) );
 set_weight(100);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("long","這個細繩是由一種會吸收日月精華的小蟲, 死後做為此索\n"
             "的原料而成, 此索在夜間有如許\多流螢成帶狀發亮, 有不錯的\n"
             "照明作用. 神奇的是把此索的索頭轉一下光就會被包在索中, \n"
             "再轉一下光又會往外邊發出。(cmds: on and off)\n");
	set("value",1);
  set("unit", "條");
  set("material", "cloth");
  set("needaward",2);
 }
 set("armor_prop/armor",1);
 setup();
}

int query_autoload() { return 1; }

void init()
{
  if( environment(this_object()) == this_player() )
  {
    add_action("do_on","on"); 
    add_action("do_off","off");
  }
}
int do_on(string arg)
{
  object me;
  me=this_player();
  if(!arg || ( arg != "light rope" && arg != "rope" && arg != "螢光索" ) ) return 0;
  if( this_object()->query_light() ) return notify_fail("索已經亮了吧..\n");
  message_vision(HIW"$N轉了一轉螢光索的索頭, 螢光索突然亮了起來.\n"NOR,me);
  this_object()->start_light(1);
  return 1;
}
int do_off(string arg)
{
  object me;
  me=this_player();
  if(!arg || ( arg != "light rope" && arg != "rope" && arg != "螢光索" ) ) return 0;
  if( !this_object()->query_light() ) return notify_fail("索沒有在發亮喔..\n");
  message_vision(HIB"$N轉了一轉螢光索的索頭, 螢光索突然不發亮了.\n"NOR,me);
  this_object()->start_light(0);
  return 1;
}
