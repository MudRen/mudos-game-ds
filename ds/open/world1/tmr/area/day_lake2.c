inherit ROOM;
void create()
{
  set ("short", "�s����ɷ|��");
  set ("long", @LONG
�s����ɪ��w�w���a, �A�i�H�ݨ즳�\�h�u�@�H�����b����, ���F
6 �� 6 ���Ѫ����ɦӧV�O
LONG);

  set("exits", ([
"south" : __DIR__"day_lake",
]));
  set("outdoors", "land");
  set("light",1);
  setup();
}
