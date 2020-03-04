// Room: /u/s/suez/tsing-yu/map_6_7.c

inherit ROOM;

void create()
{
	set("short", "�s���F�_��");
	set("long", @LONG
    �γ\�O�]������Ū��A�o�̤�_�F�_�誺�Ѥl�����R�F�\�h�A���Ӧ�
�Ǥ^���b�o�̤^�Q�A���O�h�b�S����H�z�|�C�X�өx�L���b�B�z�@�ǭᦺ
������A�ӫn��̵}ť�����Ǫ��֥��ɪ����l�O�۫C�Ӥk�l�H�����n���C
�@��ӤH�b������F����A���F�@�ǵ��x�L�ХL�̦n�n�N����I�F�A�X��
���H�h�O�a�ۤp�ĥ^�^���L�A���O�`�Ȥ�������C�u���@�Ӥ����֮a���p
�k�ġA�Բ���˪���A���F�L�ӡA�N��W���A�Ỵ������b���骺���W�A
���o���m�t��d�U�̫᪺���ǡC

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"map_7_6",
  "west" : __DIR__"map_6_6",
  "south" : __DIR__"map_7_7",
  "northeast" : __DIR__"map_5_8",
]));

	setup();
	replace_program(ROOM);
}
