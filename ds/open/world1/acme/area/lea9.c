// Room: /u/a/acme/area/lea9.c

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
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"lea1",
  "north" : __DIR__"lea6",
  "east" : __DIR__"lea2",
  "northwest" : __DIR__"lea7",
]));
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
	replace_program(ROOM);
}
