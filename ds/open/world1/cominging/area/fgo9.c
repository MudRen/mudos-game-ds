inherit ROOM;

void create()
{
	set("short", "�˪L�X�f");
	set("long", @LONG
�o�̴N�O�˪L���X�f�F�A�_��O�@�Ӽs�j���v�ϡA�j���N�O�e����
���B�F���`���F�A�A�^�Y���ҨӤ�����o�̬ۮt�ܤj�A�@��t�A�@��
�G�A�p�G�������n���H�i��|���@�I�I���Y��...�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"flurry1.c",
  "south" : __DIR__"fgo8.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
