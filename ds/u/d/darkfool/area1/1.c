// Room: /u/d/darkfool/area1/1.c

inherit ROOM;

void create()
{
	set("short", "�s�մ�������f");
	set("long", @LONG
�o�̬O�s�մ���������A��ڥ۬W���ߦb�i�X�f����ǡA���骺
�W���z�S�X�ǳ\���v���ɮ�A���̴��g�O�j���@�����A���F���q��
�Ө즹�a���s�~���̨��o��ڥ۬W���Z���S�⪺�A�K�N��O�d�F�U��
�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
