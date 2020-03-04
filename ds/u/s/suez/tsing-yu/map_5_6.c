// Room: /u/s/suez/tsing-yu/map_5_6.c

inherit ROOM;

void create()
{
	set("short", "�_�j��");
	set("long", @LONG
    �o�̬O�r�ɥj�����_�ݡA�A���_�g�L�l�D�X�h�K�O�s�q�ӫ��ΨB�F��
�x�D�A�ҥH���a�i���O�r�ɥj�����|��n�a�C�u������O�r�ɥj�����Ū�
�A�F��O�x���]�ߪ������Ať���Ū������٦��x��A�ݰ_�ӳo���񪺶ª�
��D�P�p�i�A�~���o�̧ٳƦp�����Y�C���O�ѩ�i�Ӫ����u���o�@���A��
�H��L�a����G���M�\�h�C�A�ݨ�l�D�f�ǥߤF�@���O�A���G�b�̤ݨ���
��ɦ��h���W�d�^��C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"map_4_6",
  "east" : __DIR__"map_5_7",
  "west" : __DIR__"map_5_5",
  "south" : __DIR__"map_6_6",
]));

	setup();
	replace_program(ROOM);
}
