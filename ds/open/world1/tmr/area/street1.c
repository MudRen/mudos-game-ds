// Room: /u/t/tmr/area/street1.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�@�����x�S�e�s����D�A���b���W���ɳ��|�M�H�����۸I�A���ǰ��F
���a���~�A�٦����֪��y���u�c�A�����N�ݵۨ��ީx�L�b�X�v������D��
�u�c�A�o�̫o�٦b�M�ȤH�b���F�����b�j�v���n�C���F�O�@����j���D��
�A���_�N�O�_�����f�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"city-door",
  "east" : __DIR__"street2",
]));
	set("outdoors","land");
	set("no_clean_up", 0);

set("light",1);
	setup();
	replace_program(ROOM);
}
