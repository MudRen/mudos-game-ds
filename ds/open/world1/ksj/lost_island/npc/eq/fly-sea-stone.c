// 2003.3.14  新增,由三顆 sea-stone 合併產生   by ksj
inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"翔 海 石"NOR, ({ "fly sea stone", "stone" }));
  set("long",@LONG
由三顆碧海石結合而成，碧海石互相牽引環繞密不可分，實在神奇。
它具有飛翔的力量(fly)。
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value", 1);
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
  if(!objectp(z=present("fly sea stone",this_player()) ) )
    return notify_fail("你沒有東西可以使用。\n");
  if( strsrch(file_name(env), "lost_island") != -1 )
    return notify_fail("你已經在遺世島。\n");
  if( me->is_fighting() )
    return notify_fail("你正在戰鬥中，無暇分心。\n");
  if( strsrch(file_name(env), "ppl_jail") != -1 )
    return notify_fail("此處無法使用翔海石。\n");
  if( env->query("no_recall") )
    return notify_fail("此處無法使用翔海石。\n");
  switch(random(5))
  {
    case  0: 
          message_vision(HIW"$N高舉翔海石，隨後身形化為一道白光沖向天際。\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room13");
          tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
          break;
    case  1: 
          message_vision(HIW"$N高舉翔海石，隨後身形化為一道白光沖向天際。\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room10");
          tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
          break;
    case  2:
          message_vision(HIW"$N高舉翔海石，隨後身形化為一道白光沖向天際。\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room28");
          tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
          break;
    case  3:
          message_vision(HIW"$N高舉翔海石，隨後身形化為一道白光沖向天際。\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room4");
          tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
          break;
    case  4:
          message_vision(HIW"$N高舉翔海石，隨後身形化為一道白光沖向天際。\n"NOR,me);
          this_player()->move("/open/world1/ksj/lost_island/room17");
          tell_room(environment(me),me->query("name")+"從半空中摔了下來。\n",me );
          break;
  }
  if(query_temp("used"))
  {
    message_vision(HIR"翔海石發出高熱化為灰燼了。\n"NOR,me);
    destruct(this_object());
  }
  set_temp("used",1);
  set_name(HIW"翔 海 石"NOR"(半損壞)", ({ "fly sea stone", "stone" }));
  return 1;
}
