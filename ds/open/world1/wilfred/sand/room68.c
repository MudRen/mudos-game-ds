inherit ROOM;
void create()
{
  set ("short", "�ֶ�");
  set ("long", @LONG

�۾��W��ۡG
�|�H���H�A�Y�H�Ѥv���ơA�ܤƨ��o�A�Y�H�a�ʬ���A�����۩��o�C

LONG
);
  set("exits", ([
  "north" : __DIR__"room69",
  "northeast" : __DIR__"room66",
  "southeast" : __DIR__"room61",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
