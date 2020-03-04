inherit ROOM;
void create()
{
  set ("short", "民宅");
  set ("long", @LONG
這是黃沙鎮的民宅，矮小的木製房屋，歷年的風沙使它顏色更為
黯淡，房子在大街之旁，成為一橫列，居民間往來熱絡，是個有人情
味的小鎮。
LONG
);

  set("exits", ([
  "north" : __DIR__"room16",
]));
  set("objects",([
  __DIR__"npc/npc25" : 1,
]));
  set("no_clean_up", 0); 
  set("no_kill",1);
  set("no_fight",1);  set("light",1);
  setup();
  replace_program(ROOM);
}

