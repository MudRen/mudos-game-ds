// Room: /open/world3/tmr/basic/district1.c

inherit ROOM;

void create()
{
	set("short", "��v�ϤJ�f");
	set("long", @LONG
�o�̴N�O���q�ϮǪ���v�ϡA��b�o���h�O�q�u�M�L�̪��a�H�C����
���q�u�b�o�~�N�Q�C�����c�ʦ�~�A�ҥH�o�̧����C�K�צ�v�C�o�̨ө�
�q�u�D�`��K�A���q�u�C�Ѫ��u�@�ɶ����[�C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�ۨ�" : "�@���������ۨ�A�W����ۡG�u�o�̥u�}�񵹤w�n�O�~���C�v
",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/world3/alickyuen/area/dst17",
  "south" : __DIR__"digging_street4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
