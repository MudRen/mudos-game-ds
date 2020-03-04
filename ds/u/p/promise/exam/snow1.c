inherit ROOM;

void create()
{
      set ("short", "雪路");
      set ("long", @LONG
這裡四周都是涯涯白雪，一片白茫茫的景色，令人有一種很舒服的感覺，
但是因為天氣寒冷，令你不由自主的發起抖來，北方有一條明顯的道路，亦是
唯一的出路。
LONG);
      
  set("exits", ([ 
  "north" : __DIR__"snow2",
  "south" : "/open/world1/tmr/bagi/ghat6",
  ]));

 set("outdoors", "snow"); 
 set("no_clean_up", 0);

  setup();
}

