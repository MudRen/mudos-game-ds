// Room: /open/world1/tmr/wujian/room1.c

inherit ROOM;

void create()
{
	set("short", "�L���p�D");
	set("long", @LONG
������@���A�b���·t���}�ޤ��A���G���ط������ƪ��ͪ��A
�F�F���n�T���_���o�X�C�A�`�N��o�䪺�����@�A�ٱa�۹äߪ���
�{���A�I�����I�R�n���A�V�[�Y��X�A���ߪ����ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"snake-room6d",
  "south" : __DIR__"room2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
