// Room: /u/s/superbug/train/a-20.c

inherit ROOM;

void create()
{
	set("short", "���@���㩱");
	set("long", @LONG
�o�̬O�@�����㩱�A�����ۦU���U�˪�����A�ݰ_�ӤQ����H�C�d
�i�̬O�@�Ӻ}�G���k�����b�ݩ��A�d�i�e�ٯ��۴X�Ӭ�ۭ����ݸ˪��~��
�H�A�ݰ_�Ӧ��G������Ʊ��@�ˡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"a-15.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
