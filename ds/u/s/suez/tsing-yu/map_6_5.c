// Room: /u/s/suez/tsing-yu/map_6_5.c

inherit ROOM;

void create()
{
	set("short", "�s����_��");
	set("long", @LONG
    �@���p�Ѥl����������_�ӥh�A�F�n�誺�s�������A���¤H�v�}���A
�X�өx�L���ꪺ���b���񪺫�ò�U�ͤѡA��������[�֪��p�ơC�@�ǩ~��
�^�^�������g�L�A�ǳ\�M�����~���V�A�I�Y�۩I�C�b�o�̪����_��}�w�w
�ͪ��ۥ_��ҥ��h����N�A�����W���p�᥿�̰��b�R���������A�����H��
�|�Q���񪺫ĵ��K�h���A�A�٬O������H�}�U���H�d�C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_6_6",
  "northwest" : __DIR__"map_5_4",
  "southeast" : __DIR__"map_7_6",
  "south" : __DIR__"map_7_5",
]));

	setup();
	replace_program(ROOM);
}
