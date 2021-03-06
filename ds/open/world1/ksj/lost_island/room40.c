#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIW"千古石林"NOR);
  set("long", @LONG
這裡是一處谷地，到處都是高大的化石樹木，穿梭在陰暗的石林
間讓你有種恐懼感，不知道會有什麼怪物跑出來，地面是厚厚的石灰
，無法長出任何植物，光禿禿的顯得寂寥。
LONG
);
  set("exits", ([ 
      "southeast" : __DIR__"room37",
      "southwest" : __DIR__"room39",
      "northwest" : __DIR__"room43",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  set("treasure_room3",1);
  setup();
}

void init()
{
  object me,z;
  me=this_player();

  if( objectp(z=present("_TREASURE_PAPER_3_",me) ) )
    add_action("do_dig","dig");
}

int do_dig()
{
  object me,ob;
  me=this_player();
  if( objectp(ob=present("_TREASURE_PAPER_3_",me) ) )
  {
    if( me->is_busy() )
      return notify_fail("你還在忙，沒時間進行挖掘。\n");
    message_vision(HIW"\n$N對照著圖上的位置，動手開始挖掘。\n"NOR,me);
    destruct(ob);
    me->start_busy(3);
    call_out("digging",3,1,me);
    if( !random(8) )
    {
      call_out("again",5,1,me);
      me->start_busy(7);
      call_out("digging",7,2,me);
      if( !random(8) )
      {
        call_out("again",9,2,me);
        me->start_busy(11);
        call_out("digging",11,3,me);
      }
    }
    return 1;
  }
}

void digging(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIY"\n一陣辛苦挖掘後，$N挖出了一些財寶。\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
         }
         break;

    case 2:
         message_vision(HIY"\n$N挖到滿身汗水跟泥土，又挖到了一些寶物。\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                new(__DIR__"npc/eq/gold")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/gold-armor")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/diamond-ring")->move(environment(me));
                break;
         }
         break;

    case 3:
         message_vision(HIY"\n$N把周圍五尺挖成了個大洞，終於挖出了一個寶物。\n"NOR,me);
         switch( random(4) )
         {
           case 0:
                new(__DIR__"npc/eq/diamond-necklace")->move(environment(me));
                break;
           case 1:
                new(__DIR__"npc/eq/diamond-earring")->move(environment(me));
                break;
           case 2:
                new(__DIR__"npc/eq/crystal-corslet")->move(environment(me));
                break;
           case 3:
                new(__DIR__"npc/eq/crystal-shield")->move(environment(me));
                break;
         }
         break;
  }
}

void again(int c,object me)
{
  switch(c)
  {
    case 1:
         message_vision(HIW"\n$N覺得還有寶物，於是繼續挖掘下去。\n"NOR,me);
         break;

    case 2:
         message_vision(HIW"\n$N看到四周的土色有異，於是繼續挖掘下去。\n"NOR,me);
         break;
  }
}
