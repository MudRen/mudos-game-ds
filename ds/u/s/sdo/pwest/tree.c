inherit ROOM;

void create()
{
	set("short", "����e�Ŧa");
	set("long", @LONG
�o�̬O��L�̪��@���p�Ŧa�A�Ŧa���������@�ʫD�`���j������
�q�ߦb�o�̡A��֤W���骺����蹺�۷��몺�d���A�ϧA���T�µM�_
�q�C�o�ʯ��줣���ѡA�ӥB�٫D�`���j�A��F�ݨӦ��ƤQ�ӤH�X�ꪺ
�e�סC�A�J�Ӭݬݲ��e�A�٦��Ӥ@�H������}�A�����D�̭�������C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
		"enter" : __DIR__"tree1f",
	]));
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
