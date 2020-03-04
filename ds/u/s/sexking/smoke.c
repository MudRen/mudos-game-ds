#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIC"峰や菸"NOR,({ "fun smoke","smoke" }) );
  set("long",HIM"這是一根"HIC"峰"HIM"這個排子的菸....你可以抽(suck)看看。\n"NOR);
  set("unit","根"); 
  set("food_remaining",1);
  setup();
}
void init()
{
  add_action("do_suck","suck");
}
int do_suck(string arg)
{
  object me = this_player();
  if(!arg || arg != "smoke") return 0;
  if( me->is_busy() )
  return notify_fail("你還在忙,不能吸菸...\n");
  message_vision(HIC"$N吸了吸菸....開始吞雲吐霧起來..，好不快樂。\n"NOR,me);
  me->start_busy(5);
  me->set_temp("suck1",1);
  call_out("start_suck",3,me,0);
  return 1;
}
int start_suck(object me,int f)
{
  if(!me) return 1;
  if(f < 4)
  {
    switch( random(3) )
  {
      case 0 : message_vision(HIY"$N突然嗆到了鼻子...咳了一咳嗽..\n"NOR,me);           break;
      case 1 : message_vision(HIG"$N突然感覺輕飄飄的...好像上了天堂一樣\n"NOR,me);        break;
      case 2 : message_vision(HIR"$N突然感覺到莫名的痛苦..不禁哀號了起來。\n" NOR,me); break;
  }
  call_out("start_suck",3,me,++f);
  return 1;
  }
  else message_vision(HIY"遠方突然傳來了小麥草天使的聲音:!!!吸煙不好ㄛ!!!。\n" NOR,me);
  if(this_player()->query_temp("suck1")>=5)
  {
  message("system",HIY"超級大消息：" +me->name(1)+ "由於抽了太多菸得到了肺癌死掉了...各位乖寶寶不要吸菸ㄛ\n"NOR,users());
  }
  this_object()->add("fill_suck",-1);
  if( this_object()->query("fill_suck") < 1 )
  {
  this_player()->die();
  this_object()->delete("item_desc");
  set("long",HIM"這是一根"HIC"峰"HIR"這個牌子的菸..只剩下煙蒂的部份,似乎已經抽完了。\n"NOR);
  set_name(HIC"峰や菸屁股"NOR,({ "fun smoke","smoke" }) );
  return 1;
}
}
