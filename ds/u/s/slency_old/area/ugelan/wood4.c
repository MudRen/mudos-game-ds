// Room: /u/s/slency/area/ugelan/wood4.c

inherit ROOM;

void create()
{
	set("short", "�˪L�t�B");
	set("long", @LONG
�A�����Ǧ��@�ʾ𽮭Z�K������A�ݥ����L�ڿ��`�έa�`�@���N�i
�H�ܲM�������D�o�ʯ���w���d�~���֡A�b�o�ʥ��쪺��v���餧�U
�A��L���ʦ~���𳣤w�g���⤰��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood5",
  "north" : __DIR__"wood3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	setup();
	replace_program(ROOM);
}
