// Room: /u/a/acme/area/lea2.c

inherit MOBROOM;

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
  "west" : __DIR__"lea9",
  "north" : __DIR__"lea3",
  "south" : __DIR__"lea1",
  "east" : __DIR__"lea13",
]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_max",10);
        set("mob_object",({   
           __DIR__"npc/sciurine",
        }) );
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
}
