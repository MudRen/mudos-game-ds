inherit ROOM;
void create()
{
  set ("short", "�ӹD");
  set ("long", @LONG

      �A�~��N���۫e�i�A�X�f�N�b�������e��C

LONG
);
  set("exits", ([
  "east" : __DIR__"room78",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
