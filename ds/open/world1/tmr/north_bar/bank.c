// Room: /open/world1/tmr/north_bar/bank.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@�����ΫC��ˤl�f�ئӦ��������A�D�n���M���Ѧˤl
�P�ˤl���������_�ﭱ�j�ӡA�a���H�̯��M��n����^�C�A�`�N
��F�����W�������(board)�A�W�Y�M�M�����g�ۥ���������
�����ءC
LONG
	);
	set("no_clean_up", 0);
        set("objects",([        
                __DIR__"npc/jin-kai" : 1,
        ])      );

	set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"town18",
]));
	set("current_light", 1);
	set("light", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "board" : "   ���������Ѫ��A�Ȧ�:

deposit      : �s��
withdraw     : ����     

",
]));
	set("room_type", "bank");
	set("no_kill", 1);

	setup();
	replace_program(ROOM);
}
