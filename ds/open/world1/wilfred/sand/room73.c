inherit ROOM;
void create()
{
  set ("short", "�ȪZ��");
  set ("long", @LONG

�۾��W��ۡG��D�ȪZ�A�ݥժ��A���A���A�C
LONG
);
  set("exits", ([
  "out"       : __DIR__"room49",
  "northwest" : __DIR__"room55",
  "southeast" : __DIR__"room54",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
