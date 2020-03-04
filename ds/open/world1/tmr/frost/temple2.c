// Room: /open/world1/tmr/frost/temple2.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-����");
	set("long", @LONG
�o�̬O�D�[���������A�����ѭĵ۹D�ФѴL�������A�~���@�Ӱ��j��
���l�̧�O���������A�|�g������]���ۼƦ���N�o�D�P�H���e���A���W
�ӽo�A��C�ӤH���e�o�ݮݦp�͡C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"temple1e2",
]));
	set("current_light", 2);
        set("objects", ([
                __DIR__"npc/huang-fei-hu":1,
                __DIR__"npc/taoist2": 2,
        ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
