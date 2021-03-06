#include <ansi.h>
#include <login.h>
#include <armor.h>
inherit WAIST;

string *club_area = ({ 
        "/open/world1/cominging/area/dragon/",
        "/open/world1/god_club/",
        "/open/world1/baal/ming_club/",
        "/open/world1/acme/area/sky/",
        "/open/world1/acme/area/moon/",
        });

void create()
{
  set_name(HIW+BLK"烏鴉羽毛"NOR,({"crow feather","feather"}));
  set_weight(140);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一根漆黑烏鴉的羽毛，可以裝備在腰上當作飾品，也可以有別種用途。");
    set("value",0);
    set("unit","根");
  } 
    set("armor_prop/armor",1);       
    set("armor_prop/dex",2);       
  setup();
}
void init()
{
  add_action("do_fly","fly");
}

int do_fly(string str)
{
  object obj, me = this_player(), ob = this_object();
        int i;
  if(!str) return notify_fail("請輸入對方的英文名。\n");

  if(ob->query("in_use")) return notify_fail("飛行的力量只有一次。\n");
  if( !obj=find_player(str) )
    return notify_fail("沒有這個玩家。\n");

        if( me->query_temp("ride") ) 
                return notify_fail("你的馬似乎不想跟你一起飛喔！\n");
  if(obj->money_type() != me->money_type() )
    return notify_fail(obj->name(1)+ "跟你所處的時空不同，無法飛行。\n");
  if(!environment(obj) || wizardp(obj) || environment(obj)->query("no_goto") || environment(me)->query("no_goto"))
        for(i = 0;i<sizeof(club_area);i++)
        {
        if( strsrch(file_name(environment(obj)), club_area[i]) != -1 ) 
                return notify_fail("對方在幫會區域。\n");
        }

  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIC"$N將$n"HIC"往空中一拋，$n"HIC"的表面積突然增加數倍，翔風而起！\n"NOR,me,ob);
  ob->set("in_use",1);
  ob->set("invis",1);
  me->start_busy(1);
  call_out("walk",2,obj,me,ob);
  return 1;
}

void walk(object obj, object me, object ob)
{
  if(obj)
  {
    message_vision(HIC"\n一陣狂風之後，$N己消失在眾人的面前。\n\n"NOR,me);
    me->move(environment(obj));
    write(HIW"你從烏鴉羽毛上縱身跳下，安然無恙的著地•\n"NOR);
    message_vision(HIC"\n隨著一陣狂風，$N突然出現在此地！\n"NOR,me);
    destruct(ob);
    return;
  }
  message_vision(HIR"..... 結果什麼事都沒發生\n"NOR,me);
  ob->delete("in_use");
  return;
}

