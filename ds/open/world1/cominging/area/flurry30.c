inherit ROOM;

void create()
{
	set("short", "���Y����");
	set("long", @LONG
�o�̬O���Y�����A�b�A���k���U���ж��A���L�O���o�ܳ��t���ˤl
�A�ä��e���q�~���ݨ�̭��o�ͤF���򪺱��ΡA�b�q�e�b�o����N�o��
�L�Q�H���ѹL���ơA�i�O��ӤS�[�j�F���áA�ҥH��Ӫ��ƥ�N������
�֤F�A�o�઺�Ů�M�s�A�j���O�]�����D�Ǫ��p���a�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry29.c",
  "east" : __DIR__"flurry31.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
