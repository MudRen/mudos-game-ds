// Room: /u/s/slency/area/ugelan/road1.c

inherit ROOM;

void create()
{
	set("short", "�n�����f");
	set("long", @LONG
�o�̬O�վB�����n���������f�A���Ǫ��Ъ٥�����B�A�ݵ۩P�D��
���Q�⪺�۵P���P�A�������I�f�����b�ܤU�A�o�̪���D�۷��b���
�A�Q�Ӧ����̪��k�ߥ��O�۷��Y�K���A�]���Ǧ�����ʦ~�Ӥ@���z�ߤ�
�n�A���~���j�Ұꪺ�a��A���_�O�@����j�ȩ��A�F���e�ۤ@���j��
�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road8",
  "south" : __DIR__"bigdoor",
  "east" : __DIR__"road2",
  "north" : __DIR__"inn",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
