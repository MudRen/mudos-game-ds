inherit ROOM;
void create()
{
  set ("short", "黃沙嶺");
  set ("long", @LONG
經年累月的風沙，堆出了這塊黃沙丘陵地，丘陵上寸草不生，鳥
獸難見，當地人稱之為『黃沙嶺』，此丘陵為連接舊磐龍城與黃沙道
之要道。
LONG
);
  set("exits", ([
  "west" : __DIR__"room36",
  "south" : __DIR__"room34",
]));
  set("objects",([
  __DIR__"npc/npc1" : 2,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
