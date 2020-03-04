inherit ROOM;
void create()
{
  set ("short", "幽深小徑");
  set ("long", @LONG
你己進入了山洞中，甬道內乾燥陰暗，你漸行漸遠，洞口己成為
一個小光點，甬道壁上觸手皆為岩石，石質看似脆爛，觸之卻感到甚
為堅硬。
LONG
);

  set("exits", ([
  "south" : __DIR__"room49",
  "northwest" : __DIR__"room47"
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
