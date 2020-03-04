#include <ansi2.h>
inherit NPC;
void create()
{
  set_name(HIY"液態金屬人"NOR, ({"liquefaction metal man","man"}));
  set("long",@LONG
一個全身為液態金屬做成的金屬人..它可以變成任何人
但沒有人知道它的使用方法，也許你可以想辦法去控制
它，就可讓它變成任何人了。
LONG
);
  set("unit", "個");
  set("race", "機器人");
  set("level", 1);
  set("age",1);
  set("gender","中性");
  setup();
}
void init()
{
  add_action("do_be","be");
  add_action("do_unbe","unbe");
  add_action("hest","hest");; 
}
int do_be(string arg)
{
  object who,me,obj,*inv;
  int i,max;    
  me=this_object();
  inv = all_inventory(environment(me));
  if(!arg) return notify_fail("你要讓它變成誰?\n");        
  if(me->query_temp("be") == 1) return notify_fail("請先讓它變回來原先的樣子 <unbe>。\n");
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
      me->set_temp("be", 1);
      me->set("name",       inv[i]->query("name"));
      me->set("title",      inv[i]->query("title"));
      me->set("nickname",   inv[i]->query("nickname"));
      me->set("id",         inv[i]->query("id"));
      me->set("gender",     inv[i]->query("gender"));
      me->set("guild_rank", inv[i]->query("guild_rank"));
 
   return 1;
    }
}
}
int do_unbe(string arg)
{
  object me,obj;
  int i,max;        
  me=this_object();
  if(!me->query_temp("be")) return notify_fail("它還沒變成別人\n");  
  me->set("name",       me->query_temp("bak_name"));
  me->set("title",      me->query_temp("bak_title"));
  me->set("nickname",   me->query_temp("bak_nickname"));
  me->set("id",         me->query_temp("bak_id"));       
  me->set("gender",     me->query_temp("bak_gender"));
  me->set("guild_rank", me->query_temp("bak_guild_rank"));
  me->delete_temp("be");
  me->delete_temp("bak_name",       me->query("name"));
  me->delete_temp("bak_title",      me->query("title"));
  me->delete_temp("bak_nickname",   me->query("nickname"));
  me->delete_temp("bak_id",         me->query("id"));
  me->delete_temp("bak_gender",     me->query("gender"));
  me->delete_temp("bak_guild_rank", me->query("guild_rank"));
  
  return 1;
}
int hest(string str)
{ 
object me,ccc;
me=this_player();
if(!objectp(ccc=present("item",me) ) )
return notify_fail(HIR"警告.無持遙控器者不得控制它。\n"NOR);
command(str);
  return 1; 
}


 
