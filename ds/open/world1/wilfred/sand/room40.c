inherit ROOM;
void create()
{
  set ("short", "�½Y�s��}");
  set ("long", @LONG
�q���F��U�ӡA�@�����й����A�V������ӥh�C�a�V�k���A���H
���O���F�u�u�F�ʷʦ����A���H���O�y�y�Ѧa�A���즿��X�h��\�A
���������A�R����r���I
LONG
);

  set("exits", ([
  "west" : __DIR__"room41",
  "eastup" : __DIR__"room39",
]));
  set("objects",([
  __DIR__"npc/npc24" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
