// Room: /u/s/slency/area/ugelan/cave1.c

inherit ROOM;

void create()
{
	set("short", "���t�s�}");
	set("long", @LONG
�o�̬O�@�ӳ��t���s�}�A�s���Q�����ơA���ӬO���H�b���p�w�Ӧ�
���H�u�s�}�A���L�s�}�̪ŪŦp�]�A���F�|��Ϊ��@���۫ǥ~�K�S����
�L����F��F�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wood10",
]));
	set("no_clean_up", 0);
	set("light",0);
        setup();
	replace_program(ROOM);
}
