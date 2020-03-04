inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"無"HIR"敵"BLK"萬"HIR"花"HIC"筒"NOR, ({ "super kaleidoscope", "kaleidoscope" }));
  set("long",@LONG
通過ISO 9002國際品質保證的跨時空大寶物，使用的時候只要按下fire
，就可以到達一虛幻空間！！
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

void init()
{
  add_action("do_fire","fire");
}

int do_fire()
{
  object z,me;
  me=this_player();
  if(!objectp(z=present("super kaleidoscope",this_player()) ) )
    return notify_fail(HIR"Kenshin告訴你:"NOR"請正確使用本物品!!。\n"NOR);
 message_vision(HIG"$N按下了"HIR"F I R E "HIG"鈕，突然間天色一暗，人整個消失在空氣中!!\n"NOR,me);
  this_player()->move("/u/k/kenshin/dream-fight/r5");
  if( userp(this_player()) )
    {
      message("world:world1:vision",
        HIC"\n【"HIB"武林"HIR"熱報"HIC"】"HIR""+this_player()->name(1)+HIG"穿越時空，來到了─"HIM"夢幻競技場"HIB"•••\n\n"NOR
        ,users());
    }

  tell_room(environment(me),me->query("name")+HIR" 來到了這個空間...\n"NOR,me );
  destruct(this_object());
  return 1;
}

