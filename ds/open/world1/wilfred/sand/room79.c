inherit ROOM;
void create()
{
  set ("short", "�j�s��");
  set ("long", @LONG
�o�̬O�@���s��L�ڪ��Ŧa�A���G�b���a�P���U���]�����U���A
���B���G���~���@�y���j���ؿv�A�y����s�������A�����G�~�[����
�A�ܱo�}�ꤣ���A�a�W���C�۪O�]���v�Q�p�p���F�θ����ұ��\�C
LONG
);
  set("exits", ([
  "northwest" : __DIR__"room80",
  "northeast" : __DIR__"room84",
  "south" : __DIR__"room78",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
