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
  "east" : __DIR__"room81",
]));
  set("item_desc",([
"�C�۪O" : "�o�̪��C�۪O���G���\\�h���_�A���D�i�H�U(down)�h�H\n",
]));
  set("hide_exits", ([
"down" : __DIR__"room83",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
