// Room: /u/b/bennyng/area/room9.c

inherit ROOM;

void create()
{
	set("short", "�����c���");
	set("long", @LONG
�o�̬O�����c�����A�|�P�G�����R�i�H��������A�]�������y�t��
�h�O�@�ӷR�����᪺�H�D�o�̺ئ��U���U�˪�������A���¦��զ�������
�A�D�`����A�A���T�Q�Ĥ@���Ӱe���A���R�H�D
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room10",
  "northup" : __DIR__"room8",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
