// Room: /u/a/acme/area/lea1.c

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
  "northeast" : __DIR__"lea13",
  "south" : __DIR__"lea14",
  "north" : __DIR__"lea2",
  "northwest" : __DIR__"lea9",
]));
	set("no_clean_up", 0);

    set("outdoors","land");
        set("chance",80);
        set("mob_amount",3);    //�h�̦h�X�{�T�өǪ�.
        set("mob_max",10);
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/deer",
        }) );
	setup();
}
