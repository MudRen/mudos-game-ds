inherit ROOM;

void create()
{
      set ("short", "雪之小徑");
      set ("long", @LONG
這裡四週有著許多被白雪覆蓋的植物，相對溫度也越來越寒冷，使你腳步
想加快，盡快離開這裡，找一個溫暖的地方來好好休息一番，小徑一直向上延
伸而去。
LONG);
      
  set("exits", ([ 
  "northwest" : __DIR__"snow5",
  "east" : __DIR__"snow3", 
  ]));

  set("outdoors", "snow"); 
  set("no_clean_up", 0);

  setup();
}
