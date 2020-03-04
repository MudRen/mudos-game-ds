// Room: /u/a/acme/area/lea13.c

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
  "northeast" : __DIR__"lea11",
  "north" : __DIR__"lea10",
  "west" : __DIR__"lea2",
  "southwest" : __DIR__"lea1",
]));
	set("no_clean_up", 0);
      set("outdoors","land");
     set("objects", ([
        __DIR__"npc/rabbit" : 5,
     ]));

	setup();
	replace_program(ROOM);
}
