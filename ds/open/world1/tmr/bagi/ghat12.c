// Room: /open/world1/tmr/bagi/ghat12.c

inherit ROOM;

void create()
{
	set("short", "�L���p�|");
	set("long", @LONG
�A�����b�@�����O���諸�p�|�W�A�p�|��Ǫ����F�ۤ��̰����m��A�j�j
��C�F���s�W�j�P���H���A���F�������U����������A���G��ӥ@�ɴN�O�@��
�I�R�C���訫���ƤQ�B���i�樣�@�B�j�V���C
LONG
	);
	set("outdoors", "snow");
	set("current_light", 3);
	set("no_clean_up", 0);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"ghat11",
  "west" : __DIR__"ghat13",
]));

	setup();
	replace_program(ROOM);
}
