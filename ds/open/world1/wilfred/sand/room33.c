inherit ROOM;
void create()
{
  set ("short", "�ۯ��q");
  set ("long", @LONG
�o�O�@�y�Υ��Y�ئ����p�q�A�̭����F�@�L�������~�A���򳣨S
���A�~�Y���F���j�A�q�̤@�Ф��V�A�n��������O�q���׭��F�C
LONG
);

  set("exits", ([
  "north" : __DIR__"room32",
]));
  set("objects",([
  __DIR__"npc/npc35" : 1,
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

