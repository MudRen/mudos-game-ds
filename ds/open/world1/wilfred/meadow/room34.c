inherit ROOM;
void create()
{
  set("short", "���������");
  set("long", @LONG
�o�̬O������쪺����A�ӱq�o�̶��۽Y�s������y���y��
�U�i��F�Y�s���F�䪺�����A�]���B�����L��e�s�A�󦿤j
�����سy�p�e�ŧi���ѡA�ҥH�q�`�J���O�ѫn�����i�J�C�o
�̩��F�_���O�z�_�a�ϡA�n��Z���C�Q�������h�O�s���C
LONG
);
  set("exits", ([
"east"      : __DIR__"room16",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
  replace_program(ROOM);
}
