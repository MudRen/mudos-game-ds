// Room: /open/world1/tmr/bagi/ghat8.c

inherit ROOM;

void create()
{
	set("short", "�N����`");
	set("long", @LONG
�o�B�N�O�K���t��_�Ҥ��@�i�N����j�A�]�������s�p�̰��I�A��
�ѤW����v�Ө�������B�h�ɥ��~���R�A�ҥH�N����]���o�W�C�Aı�o��
��V�ӶV�N�A�ѩ�j���л\�D���A�w�g�L�k����F�n��_�C�|�P���F�կ�
�����ᤧ�~�A�N�u�����e���j�B��C
LONG
	);
	set("world", "past");
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"ghat6",
  "east" : __DIR__"ghat9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
