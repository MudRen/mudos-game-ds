inherit ROOM;
void create()
{
  set ("short", "�C�s��");
  set ("long", @LONG

�۾��W��ۡG�_�D�C�s�A�ݶ¤��A�U���ѯh�A���I���A�u�V�C

LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northeast" : __DIR__"room57",
  "southwest" : __DIR__"room56",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
