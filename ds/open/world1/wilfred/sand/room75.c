#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "�ӹD");
  set ("long", @LONG
�Ө�o�̡A�u��N���e�i�A�i�D�����A�X�G̽�⤣�������A�u��
�y�ѨӸ����L������ƪ��A�b�e�Y�������ӥX�f�A���}�̩��t�����A
�u��̵}�ݨ�۸O�g�ۡG�i�U�s�j�ӡj�C
LONG
);

  set("exits", ([
  "north" : __DIR__"room76",
]));
  set("no_recall",1);
  setup();
}

void init()
{
  write(HIW""BLK"�e����G���ǥ��G.... �V�|�A�Ӹ��v�L�k���ѡA�{�b�u���~��e�i�F�C\n"NOR);
}
