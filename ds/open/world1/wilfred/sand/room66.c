inherit ROOM;
void create()
{
  set ("short", "�ֳ�");
  set ("long", @LONG

�۾��W��ۡG
�|�H���H�A�Y�H�Ѥv���ơA�ܤƨ��o�A�Y�H�a�ʬ���A�����۩��o�C

LONG
);
  set("exits", ([
  "south" : __DIR__"room67",
  "northwest" : __DIR__"room65",
  "southwest" : __DIR__"room68",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
