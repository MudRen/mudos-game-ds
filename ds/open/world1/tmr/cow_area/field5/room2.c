inherit ROOM;
void create()
{
  set("short", "�������n��");
  set("long", @LONG
��g�������������{��A�A�Ө�F������쪺�n��A�q
�o�̩��_�����쪺�t�@��O�z�_�a�ϡA�Ӧ���O�Y�s���A
�n��O�s���C
LONG
);
  set("exits", ([
"north"    : __DIR__"room12",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
}

int valid_leave(object me, string dir)
{
  if( dir == "out" && !userp(me) ) return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}
