// Room: /u/a/acme/area/lea14.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�o�̬O�@��L�ڪ��j���A�|�P�����o�õL�G�ˡA���W�Y���\�h��
�����ɱ����b�]�ۡA�L���������j�صۧA���y�F�A�߯ݷP��@�ѵL������
�Z�A�|�P���o�۫C�󪺮𮧡A�A�u�Q�������֩�ۤj�۵M�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pass4",
  "north" : __DIR__"lea1",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
