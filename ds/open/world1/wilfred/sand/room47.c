inherit ROOM;
void create()
{
  set ("short", "�s�}");
  set ("long", @LONG
�g�L������骺�����A�Ө�F�@�Ӥs�}�A�s�}�ä��Ƽe�s�A�ȯ�
�e�ǤG�T�H�æ�A�}�������O�͡A�����p�H�@�밪�j�A�ݨӳo�̤v�[
���H��C
LONG
);

  set("exits", ([
  "north" : __DIR__"room46",
  "southeast" : __DIR__"room48",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
