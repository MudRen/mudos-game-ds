// Room: /u/t/tmr/room/room1.c

inherit ROOM;

void create()
{
	set("short", "[1;35m�����⪺�ж�[0m");
	set("long", @LONG
�o�O�P�P�̪��ж��A�|�g���W�H����m���o���A�ж���B�\���F
�i�R�������������A�Ф����i�j�j�����H�ɡA�Υկ���_�ӡA�R���i
�R�w�֪���^�C
LONG
	);
	set("current_light", 1);
        set("valid_startroom", "1");

	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"square",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
