inherit ROOM;
void create()
{
  set ("short", "�ժ��");
  set ("long", @LONG

�۾��W��ۡG�F�D�ժ�A�ݤ�A���p�A�ʳ߰ʡC

LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northwest" : __DIR__"room50",
  "southeast" : __DIR__"room51",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
