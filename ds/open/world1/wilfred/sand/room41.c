#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "�½Y�s��}");
  set ("long", 
"�Ө�@�j���������e�A�����W�Ѧ����y"HIR"�Y�s��"NOR"�z�G�r�A����H�ҮѡA\n"
"�w���i�ҡA�r��j�嶯�_�C�b�������ǡA�|�t���۸O�A�W�Y�g���K�K\n"
"�³ª���ѡA���H�ݲM�C\n"NOR
);

  set("exits", ([
  "east" : __DIR__"room40",
  "west" : __DIR__"room42",
  "north" : __DIR__"room43",
]));
  set("item_desc", ([
  "�۸O" : "�@�¦b�f�A�Q�~�\\�a���[�A�����ʭ��s�C\n�d�j�y�ǡA�U�N�D�k�����A���[��L�ɡC\n\n--�Ѿ��l--\n",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
