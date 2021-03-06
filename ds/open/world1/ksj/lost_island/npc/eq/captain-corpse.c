#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("船長的屍體", ({"captain's corpse","corpse"}));
  set("long",@LONG
一具上面附著些許血肉的白骨，從衣物碎片可以猜出大概是一位船長
，真不幸地命喪於此，找一下也許留有什麼遺物。
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "具");
    set("volume",1);
    set("value",0);
    set("no_get",1);
  }
  setup(); 
}

void init()
{
  add_action("do_search","search");
}

int do_search(string str)
{
  object me,ob;
  me=this_player();
  ob=new(__DIR__"captain-hat");

  if( me->is_busy() )
    return notify_fail("你還在忙，沒時間檢查。\n");
  if( me->is_fighting() )
    return notify_fail("你正在戰鬥中，無暇分心。\n");
  if(!str || str!="corpse")
    return 0;
  else
  {
    message_vision("\n$N仔細找了找骨骸及四周，在散落的骨骸中找到一頂還蠻完整的帽子。\n"NOR,me);
    ob->move(me);
    me->start_busy(2);
    destruct(this_object());
  }
  return 1;
}
