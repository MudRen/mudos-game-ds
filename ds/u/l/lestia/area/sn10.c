// Room: /u/l/lestia/area/sn10.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L");
	set("long", @LONG

�@�����𸭦b�A�Y�W���R�ۡA�ǳ\�������ǵ۸��P�������_�ج�g�L��
�A�ϱo�a�W�¦⪺�𽮯B�{���I�I���ɡA�ǻ����������F�۱ЫK�O���é�o
���s�j���˪L�����A�\�h���߾ǲ߹D�N���H�̳��Q���e���������t�a�A����
�G���F�F�۱Ю{���~�A�èS���H����}�Ѷi�J�t�a����k�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"sn9",
  "south" : __DIR__"sn11",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
