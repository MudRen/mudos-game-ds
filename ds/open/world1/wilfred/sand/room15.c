inherit ROOM;
void create()
{
  set ("short", "�Q�r���f");
  set ("long", @LONG
�A�Ө�@�Ӥp�p���Q�r���f�W�A�F��M����n����۴X��H�a�A�ӫn
��A�L�h�K�����F���F��A������F���줤�F�A�_�䦳�y�C���C
LONG
);

  set("exits", ([
  "east" : __DIR__"room19",
  "west" : __DIR__"room16",
  "north" : __DIR__"room13",
  "south" : __DIR__"room24",
]));
  set("objects",([
  __DIR__"npc/npc14" : 4,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
