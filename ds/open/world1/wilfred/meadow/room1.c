inherit ROOM;
void create()
{
  set("short", "���p��");
  set("long", @LONG
�q�s���Цa�Ǫ��p�����ӡA�|�g�����󺥦h�A�o�̬O�@���d
��p�|�A�u�~�L�ƯS�O������C�}���U���H�ۤl�Q�A��o�ست�
�T�A�q���V�_���ر�h�A�o���p�������ݦ��G�O�ӯ��C
LONG
);
  set("exits", ([
  "enter" : __DIR__"room2",
  "south" : "/open/world1/tmr/area/ms2",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  set("objects",([
"/open/world1/tmr/area/npc/dog" : 1,
]) );
  setup();
  replace_program(ROOM);
}
