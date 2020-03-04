#include <ansi2.h>
inherit COMBINED_ITEM;

void create()
{
  set_name(HIM"粉盒"NOR, ({"box"}));
  set("long","附有鏡子的小小粉盒。\n使用方法: 化�� pra <某物(人)>\n卸�� unpra\n");
  set("unit", "盒");
  set("base_unit", "盒");
  set("base_weight", 1);
  set_amount(1);
}

void init()
{
  if( this_player()==environment() )
  add_action("do_pra","pra");
  add_action("do_unpra","unpra");
}
int do_pra(string arg)
{
  object me,obj,*inv;
  int i,max;        
  me=this_player();
  inv = all_inventory(environment(me));
  if(!arg) return notify_fail("你要扮成誰?\n");        
  if(me->query_temp("pra") == 1) return notify_fail("請先卸妝 <unpra>。\n");
  for(i=0; i<sizeof(inv); i++)
  {
    if( arg == inv[i]->query("id"))
    {
      me->set_temp("bak_name",       me->query("name"));
      me->set_temp("bak_title",      me->query("title"));
      me->set_temp("bak_nickname",   me->query("nickname"));
      me->set_temp("bak_id",         me->query("id"));
      me->set_temp("bak_gender",     me->query("gender"));
      me->set_temp("bak_guild_rank", me->query("guild_rank"));

      me->set_temp("pra", 1);

      me->set("name",       inv[i]->query("name"));
      me->set("title",      inv[i]->query("title"));
      me->set("nickname",   inv[i]->query("nickname"));
      me->set("id",         inv[i]->query("id"));
me->set("gender",     inv[i]->query("gender"));
      me->set("guild_rank", inv[i]->query("guild_rank"));

      write(HIW"你拿出粉盒撲撲撲的扮成了"HIY+inv[i]->query("name")+"\n"NOR);
      say("你突然覺得渾身不對勁，好像有股力量被人家吸走了。\n"NOR);
      return 1;
    }
  }
  return notify_fail("這裡沒這個人\n");
}

int do_unpra(string arg)
{
  object me,obj;
  int i,max;        
  me=this_player();
  if(!me->query_temp("pra")) return notify_fail("你沒化��!!\n");  
      
  me->set("name",       me->query_temp("bak_name"));
  me->set("title",      me->query_temp("bak_title"));
  me->set("nickname",   me->query_temp("bak_nickname"));
  me->set("id",         me->query_temp("bak_id"));       
  me->set("gender",     me->query_temp("bak_gender"));
me->set("guild_rank", me->query_temp("bak_guild_rank"));

  me->delete_temp("pra");

  me->delete_temp("bak_name",       me->query("name"));
  me->delete_temp("bak_title",      me->query("title"));
  me->delete_temp("bak_nickname",   me->query("nickname"));
  me->delete_temp("bak_id",         me->query("id"));
  me->delete_temp("bak_gender",     me->query("gender"));
  me->delete_temp("bak_guild_rank", me->query("guild_rank"));

  write(HIW"你將�菬齯F, 回復原本的面貌\n"NOR);
  return 1;
}

