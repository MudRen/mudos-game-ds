// Room: /u/l/lestia/area/map_5_6.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�۪O�D��");
	set("long", @LONG

�A�����b�@���ᬰ�e�����p�D�W�A�p�D�O�Υ۪O�@���@������Ӧ����A
�]���~�N���I�[�F�A�ҥH�ݰ_�Ӧ��I�}�H������A�p�D����ٺغ��F���
���A�ϤH�����������@�G�A�X�����Ԫ��e���]���۱Ļe�A�ݨe�̧V�O��
�ˤl�A�ϧA�]�U�w�M�߭n�n�n���V�O�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"map_5_7",
  "west" : __DIR__"map_5_5",
  "south" : __DIR__"map_6_6",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
