// Room: /u/s/suez/tsing-yu/map_7_6.c

inherit ROOM;

void create()
{
	set("short", "�j�s��");
	set("long", @LONG
    �A�@��J�o�̡A�N�Q�o�̪����m���~��C�e�j���p�@�Ӥp�����Ŧa�W
�A�Ȧ�ߵۤ@���Z�i�w�[���ɥۡA�H�Τ@�f��������b�����\���Cť���b
�M��H�β`�]�A�|�Ѭ\�����ǥX�۱��n�A���P���{�צn���S���H�^��j��
���Գ��A�[�W�Ѯl�D�j�Ӫ�����s���A���b�o�̪��A�Aı�o�t�W�N�����N
�W�۱r�ަb���v���x�y�����A�ݵۤ@���ͥͦ����N�O�O�D�D�A�A��Mı�o
�n���ݲM�H�����@���A�o�S�줣��ۧڦs�b���Pı�C�ݵۿW�ߦb���e���j
�ɡA�A���ߤ����T�@�}�ķ��C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 8 */
  "southwest" : __DIR__"map_8_5",
  "east" : __DIR__"map_7_7",
  "north" : __DIR__"map_6_6",
  "northwest" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_5",
  "southeast" : __DIR__"map_8_7",
  "south" : __DIR__"map_8_6",
  "northeast" : __DIR__"map_6_7",
]));

	setup();
	replace_program(ROOM);
}
