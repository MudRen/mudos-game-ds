// Room: /d/shaolin/shandao3.c

inherit ROOM;

void create()
{
	set("short", "�s�D");
	set("long", @LONG
�o�O�@���������s���V�W�詵���A�@�����S�_���������A�s
�D�������O�@���A�˪L�A�p������s�n�M���j�L�˪L���F�F�n��
´�����R���j�۵M���۫ߡC�k���O�~�k���s�V�C���W�g�`��ݨ�
�L�ӹ��H�Өө����A�V�W�@�����N�O�ۦW���֪L�x�F�C
LONG
	);

	set("outdoors", "land");

	set("exits", ([ /* sizeof() == 3 */
	"northup" : __DIR__"shandao2",
	"west" : __DIR__"zhulin/entry",
	"southdown" : __DIR__"shandao4",
]));

	setup();
	replace_program(ROOM);
}
