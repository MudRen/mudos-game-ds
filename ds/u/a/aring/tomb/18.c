// Room: /u/a/aring/tomb/18.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�o�̪��a�W�Q���o�äC�K�V�A�X������
��w�g���@�b�r�S�X�ӡA�z�L�û\���_�جݶi�h�A�ç��̭����M�O�Ū��C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"19.c",
  "east" : __DIR__"17.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
