#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("破爛的羊皮紙", ({"treasure paper","paper","_TREASURE_PAPER_3_"}));
  set("long",@LONG
一張破爛的羊皮紙，上面有被火燒、刀割、蟲蛀等等痕跡，看來年代
應該相當久遠了，羊皮紙上畫著像是地圖的圖案。

          ★

                          
                        ╱
                      □ 
                ╱   
                        －□  □
                  ｜          ｜
            
                      ｜    
                －□          □
              ｜          ｜  ｜
              
                      ｜  
                    －□

圖上註解著詳細的相對位置，在一個箭頭旁畫著挖掘(dig)的圖樣。
LONG
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");
    set("volume",1);
    set("value",0);
  }
  setup(); 
}

void init()
{
  object me,z,env;
        if(!userp(environment(this_object()))) return;

  me=this_player();
  env=environment(me);

  if( !env->query("treasure_room3") )
    add_action("do_dig","dig");
}

int do_dig()
{
  object me,z;
  me=this_player();

  if( me->is_busy() )
    return notify_fail("你還在忙，沒時間進行挖掘。\n");
  if( !me->query_temp("weapon") )
    return notify_fail("你兩手空空，無法挖掘地面。\n");

  message_vision(HIW"\n$N看看看四周景色，突然若有所悟，於是隨手丟下紙張開始挖掘。\n"NOR,me);
  me->start_busy(5);
  call_out("dig_nothing",4,me);
  return 1;
}

void dig_nothing(object me)
{
  switch( random(3) )
  {
    case 0:
         message_vision(YEL"\n$N挖了老半天，只挖出了一個大土窪。\n"NOR,me);
         destruct(this_object());
         break;

    case 1:
         message_vision(YEL"\n突然鏗然一聲響，$N暗自竊喜，但仔細一看原來是一塊石頭。\n"NOR,me);
         destruct(this_object());
         break;

    case 2:
         message_vision(YEL"\n$N挖著挖著居然挖出水來，弄得自己又濕又髒，卻一無所獲。\n"NOR,me);
         destruct(this_object());
         break;
  }
}
