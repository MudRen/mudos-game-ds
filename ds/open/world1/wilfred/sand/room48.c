inherit ROOM;
void create()
{
  set ("short", "�ղ`�p�|");
  set ("long", @LONG
�A�v�i�J�F�s�}���A�i�D�����곱�t�A�A���溥���A�}�f�v����
�@�Ӥp���I�A�i�D���WĲ��Ҭ����ۡA�۽�ݦ�����AĲ���o�P���
����w�C
LONG
);

  set("exits", ([
  "south" : __DIR__"room49",
  "northwest" : __DIR__"room47"
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
