inherit ROOM;
void create()
{
  set ("short", "��D");
  set ("long", @LONG
��̳W�ҷ��p�A�u���@���j��A���]���֡A��W���F�u�u�A��
�H�@���Y�D�A�������~�ӫȦb�����ʡC
LONG
);
  set("exits", ([
  "east"  : __DIR__"room12",
  "north" : __DIR__"room10",
  "south" : __DIR__"room13",
]));
  set("objects",([
  __DIR__"npc/npc13" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
