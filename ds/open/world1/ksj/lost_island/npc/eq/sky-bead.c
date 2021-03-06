inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIC"天翔珠"NOR, ({ "sky bead", "bead" }));
  set("long",@LONG
由樵老所造，可直接飛向東方日出之島(fly)。
LONG);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 1000);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

void init()
{
  add_action("do_fly","fly");
}

int do_fly()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("sky bead",this_player()) ) )
    return notify_fail("你沒有東西可以使用。\n");
  if( strsrch(file_name(env), "east_island") != -1 )
    return notify_fail("你已經在東方日出之島了。\n");
  if( me->is_fighting() )
    return notify_fail("你正在戰鬥中，無暇分心。\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
    return notify_fail("此處無法使用天翔珠。\n");
  if( env->query("no_recall") )
    return notify_fail("此處無法使用天翔珠。\n");
  message_vision(HIW"$N雙手合握天翔珠，隨後身形化為一道白光沖向天際。\n"NOR,me);
  this_player()->move("/open/world1/ksj/east_island/room1");
  tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
  destruct(this_object());
  return 1;
}
