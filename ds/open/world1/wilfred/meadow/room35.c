inherit ROOM;
void create()
{
  set("short", "�z�_�������");
  set("long", @LONG
���B����Ťv�����ܱo�H�N�A��ԻP����a�Ϥj����
��A�b�_�价�B�i�����ݨ��Ʈy���s�A�s���ѤѡA�s
�q�ճ��q�q�A�M���@���Ȧ�@�ɡC
LONG
);
  set("exits", ([
"south"     : __DIR__"room30",
]));
	set("objects", ([
	]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
  replace_program(ROOM);
}
