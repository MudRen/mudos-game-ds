inherit ROOM;
void create()
{
  set ("short", "������");
  set ("long", @LONG

�۾��W��ۡG�n�D�����A�ݨ����A�����~���A���R�C

LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northeast" : __DIR__"room52",
  "southwest" : __DIR__"room53",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
