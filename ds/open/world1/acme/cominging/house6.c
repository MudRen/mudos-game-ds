inherit ROOM;

void create()
{
	set("short", "�O��");
	set("long", @LONG
�o�O�@�����F�޲z�x�O�H�Ƥ����D���B�A�b�o�̦��G�H�s�֤F�ܦh
�A�ä�������H�Ө�o�A�`�`�ݨ��̭����H�b���O�ΡA�]�g�`���S���H
�ӡA�ҥH�x�O�����ɷ|�ä����M���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"path7",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
