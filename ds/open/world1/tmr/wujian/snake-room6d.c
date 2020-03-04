// Room: /open/world1/tmr/wujian/snake-room6d.c

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
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"jian3",
  "east" : __DIR__"jian1",
  "up" : "/open/world1/moonhide/area/snake-room6",
  "west" : __DIR__"jian2",
  "south" : __DIR__"room1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
