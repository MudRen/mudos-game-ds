// Room: /u/s/suez/tsing-yu/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "�s���F");
	set("long", @LONG
    �F���ƨӰ}�}���y�A�^�椧�n�y�y���_�C�X�Ӧ~�����h�l���b��f��
�ۨө����k�Ĥl�~�Y�ר��C�@�Ǧ����H���ꪺ�]���_��A���۰����Өӥh
�h�C�|�P�����W�����F��O�A���ꪺ���C����A�@�s��۬��R���k�l�@
��ͯ��@��N�Ȫᵷ���@�����F�詹��W�j�A���Ө��Ӫ��Q���H�g�L�H��
�d�U�F�O�H����������A���O�����o�q�Ӥ��b����F��W���d�C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "southwest" : __DIR__"map_8_6",
  "east" : __DIR__"map_7_8",
  "north" : __DIR__"map_6_7",
  "northwest" : __DIR__"map_6_6",
  "west" : __DIR__"map_7_6",
  "south" : __DIR__"map_8_7",
]));

	setup();
	replace_program(ROOM);
}
