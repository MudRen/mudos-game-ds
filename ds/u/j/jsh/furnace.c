#include <path.h>
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("武融爐",({"weapon furnace","furnace"}));
  set_weight(99999999);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG
鐵匠專用的融爐，主要是用在武器的融合，但求此方法來煉製
的人是少之又少。

  使用方法： 
  1：先放入兩種武器
  2：升爐火(fireup)

LONG
);

  }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_fireup","fireup");
}

int do_fireup()
{
  object ob = this_object(), *obs, *only_check;
  int i, index = 0;

  obs = all_inventory(ob);
  if(sizeof(obs) < 1) return notify_fail("你要放入東西才能融合。\n");
  if(sizeof(obs) > 2) return notify_fail("你放入的東西太多了！！\n"[30m);[0m
  message_vision("\n$N升起了爐火，開始武器的融合 ...... \n\n",this_player());


  if(sizeof(obs) > 2)
  {
    message_vision("\n結果什麼事都沒發生.... \n\n",this_player());
    return 1;
  }
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "white crystal") index += 10;
    if(obs[i]->query("skill_type") == "sword") index += 100; 
  }

  only_check = filter_array( children(WD_PAST+"sand/npc/wp/wp12"), (: clonep :) );

  if(index != 110 || sizeof(only_check) > 0 )
  {
    message_vision("\n結果什麼事都沒發生.... \n\n",this_player());
    return 1;
  }

  for(i=0;i<sizeof(obs);i++)
    destruct(obs[i]);

  tell_room(environment(ob),HIW"丹爐裡爆射出一陣強光 ...... 你看到丹爐裡似乎冶煉出新的物事？\n"NOR);
  new(WD_PAST+"sand/npc/wp/wp12")->move(ob);
  return 1;
}

