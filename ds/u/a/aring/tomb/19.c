// Room: /u/a/aring/tomb/19.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�X�W�b�˪��Q�r�[�W�観"�L�W�ħL����"�A
�W���ٱ��ۤ@���}�ꪺ�Y��... ���b�o�ئa��A�i�঺��]�|���o�w��a�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"18.c",
  "west" : __DIR__"20.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
