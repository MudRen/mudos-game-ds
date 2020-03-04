// Room: /u/k/king/area/r20.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
�o�O�@�Ӧa�դ��A�s�j�L�񪺳���A���b�Ĥ@���J�����e�A�Z��
�᪺�J���K���ʨӤV���A���e�����Q�Ū�����A�@�Ŧ��b�ӤH���A�䧻
�j����եO�H��A�A�����e�᳣���۬W�A�W����F�\�h�᯾�A�۷���
�A���ӳ����ѩ^�ӥ@���N�����A�q�ӯ��Ӵ��A�ӤA�A�����A�p�H�A�ҤA
�A�ҥ����A���i�A�j���A�Ҥ��A�Ҩ��A�Ө��A�k�f�A�J�١A�̡A�ҫw�A
�l�A�b�u�A�Ҥ����A�ҥf���A�Ҩ��x�A�Ҧ����A�ݡA�Ҥp�ҡA�ֶ��A��
���A�����A�ҥ�C�Ӥ����̤j���@�L�J���A�K�O�Ĥj�Ӵ¤G�Q�K�N�ӫ�
�A�i���j�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r21",
  "north" : __DIR__"r19",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wind" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
