
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIM"三聚氰胺饅頭"NOR, ({ "melamine manto","manto","objmanto" }));
  set("long",@LONG
2008大事紀之一，請google。

(雖然心底有個聲音要你別試，不過就是有衝動想嚐一口(taste))

(最下方還有一行幾乎看不到的小字﹕體虛，精血不足兩百請小心)
LONG
);
  set_weight(999999999);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get", 1);
    set("no_sac", 1);
    set("no_put", 1);
    set("no_auc", 1);
    set("unit", "顆");
  }
  setup();
}

void init()
{
  add_action("do_eat", "taste");
}

int do_eat(string arg)
{
  object ob,me;
  me = this_player();
  ob = this_object();
  if( !ob ) return 0;
  if( !ob->id(arg) ) return 0;
  if( me->is_busy() )
    return notify_fail("你上一個動作還沒有完成。\n");
  me->receive_damage("hp",200,ob);
  me->apply_condition("poison", me->query_condition("poison")+(random(6)+5) );
  if( me->query_condition("blooding") > 5)
    me->apply_condition("blooding", me->query_condition("blooding")-(random(3)+1) );
  if( me->is_fighting() )   {  me->start_busy(2); }else{me->start_busy(1);}
  message_vision(HIM"$N左瞧右看踟躕一下，終究還是忍不住誘惑偷偷咬了一小口...\n" NOR,me);
  tell_object(this_player(),"你感覺體內的器官一陣攪痛"HIR"(200)。\n"NOR);
  return 1;
}
