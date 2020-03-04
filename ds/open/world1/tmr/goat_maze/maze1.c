// Room: /open/world1/tmr/goat_maze/maze1.c

inherit ROOM;

void create()
{
	set("short", "�Ϩk���g�c-�J�f");
	set("long", @LONG
�b�A���e�O�@�D�P�𸭾�K���X�b�@�_�������A�����W�J���O���Y����
���A�i�ۼL�����b�o�ۤ���C�o�y�������O�y�g�c���J�f�A���۪L�۶i�h
�A�O�����Y��j�}���g�c�D���A��y�g�c���G�O�q�X�d�~�e�A�N�Q�ئb�o��
�L���̲`�B�A�P�~�ɧ����������j���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"maze2",
  "southeast" : "/open/world1/tmr/north_forest/sn1",
]));
	set("current_light", 4);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
