inherit ROOM;
void create()
{
  set ("short", "右磐龍殿");
  set ("long", @LONG
跟左磐龍殿相比，這裡右磐龍殿的格局便顯得狹小，屋內約五十
尺見方，在正中央有個大丹爐，丹爐外頭被潻以黃金色粉，在提耳部
分有著兩隻黃龍，爐高約八尺，看來是術士之練丹用房。
LONG
);
  set("exits", ([
  "west" : __DIR__"room90",
]));
  set("objects",([
  __DIR__"npc/obj/obj29" : 1,
]));

  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
