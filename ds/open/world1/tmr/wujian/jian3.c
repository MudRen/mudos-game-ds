// Room: /open/world1/tmr/wujian/jian3.c

inherit ROOM;

void create()
{
	set("short", "���~�L��");
	set("long", @LONG
�L���O��жǻ����Ҵ��쳡���H����Ҩ쪺�a�����A�D�k�̴ݻ�
���@�ӡC�m�I�L�g�n�ĤQ�E���u�K�j�a�����̡A�٬��L���a���A���L
���_�D���j�W���N�A�G�����W�v�F�L�����T�G�ɵL���A�ŵL���A���~
�L���A�Ǥ��E�o�̥üZ���ɡA�ɨ��׷����L���C�o�䪺����D�`�@�A
���H�Ѫ��A�I�����I�R�n���A�V�[�Y��X�A���ߪ����ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"snake-room6d",
]));
	set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/coffin.c" : 1,
                __DIR__"npc/belly-head.c" : 1,
                __DIR__"npc/yeroad.c" : 1,
        ]));


	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
