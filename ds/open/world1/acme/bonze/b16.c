// Room: /open/world1/acme/bonze/b16.c

inherit ROOM;

void create()
{
	set("short", "�j���_��");
	set("long", @LONG
�o�̴N�O�x���̬����Y���t�a�A�b�A���e���@�L��T�H�ٰ����j
��A�J�ӱ�h�A���ӬO�@�L���{�ȥ���A��e�����A�b��e���p�s��
�̡A��m�F�ƥH�ʭp����Z�A�Z�e�U�\��F�@�Ӥ쳽�A���a���N�O�M
�|�̰����B�߽Ҫ��a��F�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"b14",
]));
set("objects",([
    __DIR__"npc/master.c" : 1,
]) );
        set("valid_startroom", 1);
        set("light",1);

	setup();
	replace_program(ROOM);
}
