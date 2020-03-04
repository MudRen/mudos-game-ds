// Room: /u/a/aring/tomb/16.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�o�ӼX�Ӹ�������A�W���л\�ۥ��ƪ�
�۪O�A�X�W���Q�r�[�h�O�ί¥զ���Y�J���A�u���L���_�����F�@
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"17.c",
  "east" : __DIR__"15.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
