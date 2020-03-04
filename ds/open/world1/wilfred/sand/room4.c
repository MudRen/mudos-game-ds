inherit ROOM;
void create()
{
  set ("short", "黃沙道");
  set ("long", @LONG
這裡是廣大的黃沙平原中，唯一的一條國道，只見道上黃沙滾滾
，大風吹起便如一道道的黃色暴風，路上寸草不生，景色甚為荒涼，
遠處有塊丘陵地當地人稱之為『黃沙嶺』，商隊如要從朝天前往磐龍
城，一定要行經這道路，所以黃沙道也有『龍道』的別稱。
LONG
);

  set("exits", ([
  "east" : __DIR__"room3",
  "west" : __DIR__"room8",
  "north" : __DIR__"room5",
]));
  set("objects",([
  __DIR__"npc/npc16" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
