inherit ROOM;
void create()
{
        set("short", "����");
        set("long",@LONG
�A�C�B������F�o�̡A�b�_�䦳�@�}�}���Ԯ��n�ǤF�L�ӡA�A���T
�n�Y�@ť�A��ӬO�@�a�p�Ѧb�W�Ҥ��A���F��O�n�j��A�ө����h�O
�������ਤ���a��A�_�䪺Ū���n�O�A���ѱo��ۮԮԤW�f���F�U�h
�F�C
LONG
        );
        set("exits", ([
  "west" : __DIR__"sidestreet2.c",
  "east" : __DIR__"sidestreet4.c",
  "north" : __DIR__"seminary.c",
]));

        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

int valid_leave(object me, string dir)
{
  ::valid_leave();
  if( dir=="north" && !userp(me))
  return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}


