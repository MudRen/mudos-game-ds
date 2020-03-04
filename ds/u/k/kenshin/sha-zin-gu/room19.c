// Room: /u/k/kenshin/sha-zin-gu/room19.c

inherit ROOM;

void create()
{
	set("short", "�¸t����");
	set("long", @LONG
�o�����Q�v�騦���~���ҩw���¸t�����A�C�{�θ`�Ϊ̪�@�Q��
�A��a�~�����|�V�e�ѫ��A�Ӫ�F�ߤ��ﯫ�����R���P�L�q�C���F��
�`�|�e���A���̥D�n����]�O���y�x�q������w�k梤Ӯv���D��S
�O�����A�ҥH�b�v�騦�~�����ߤ��A�L���a��O�~�������M���U��
�R���C
LONG
	);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room20",
  "east" : __DIR__"room10",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
