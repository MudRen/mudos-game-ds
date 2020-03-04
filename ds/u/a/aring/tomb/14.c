// Room: /u/a/aring/tomb/14.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�X�Ӥ������Ӥj�}�A�}�̭��O�@�ӪŪ�
�ä�A�|�P���\�h���O�첪������A�V�ݶVı�o�o��C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"13.c",
  "south" : __DIR__"15.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
