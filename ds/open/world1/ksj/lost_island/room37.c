// 2003.4.13 MOBROOM->ROOM  by ksj
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "遺世島－"HIW"千古石林"NOR);
  set("long", @LONG
這裡是一處谷地，到處都是高大的化石樹木，穿梭在陰暗的石林
間讓你有種恐懼感，不知道會有什麼怪物跑出來，地面是厚厚的石灰
，無法長出任何植物，光禿禿的顯得寂寥。
LONG);
  set("exits", ([
      "southwest" : __DIR__"room36",
      "northwest" : __DIR__"room40",
     ]));
  set("no_clean_up", 0);
  set("outdoors","forest");
  set("no_auc", 1);
  setup();
}

void reset()
{
  if( this_object()->query_temp("give_armor") )
  {
    set("objects",([
        __DIR__"npc/chimera":2,
       ]));
  }
  else
  {
    set("objects",([
        __DIR__"npc/chimera":2,
        __DIR__"npc/eq/apollo-stele":1,
       ]));
  }
  ::reset();
}
