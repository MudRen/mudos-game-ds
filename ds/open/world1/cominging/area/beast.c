inherit ROOM;
void create()
{
	set("short", "�B�F���F�j���");
	set("long",@LONG
�A���b�@���u�u���j���W�A�γ\�A�b��ҫ��|���o��u�S�o��j
���j���A���L�o�o�O�B�F���������U�A�ǻ��b�F�j�󪺳̨��������@��
�ǥX���Z�N�a�A���L��Ӭ��F���m�B�F���~���ĤH�]�ӾԦ��A����H��
�A�A�]���j�a��󨺤@���a�D�`���L�q�A�ҥH�o����]���s���v�󪺯S
��s�k�A�o���ٺ��z�X�@�I�q�����s�����O���C
LONG
	);
	set("exits", ([
  "west" : __DIR__"boo-lin.c",
  "east" : __DIR__"beast1.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
