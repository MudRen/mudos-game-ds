// Room: /u/s/slency/area/ugelan/sell.c

inherit ROOM;

void create()
{
	set("short", "��Q");
	set("long", @LONG
�o�̬O�@���j����Q�A�d�l���\���F�_�ò��_�A�E�ݤ��U�X�G���O
���ȳs�����_���A�Q����b�o�󨤰������a�a�|���o��@���j��Q�A�A
�i�H�N���W���~���b���A�]�i�H�V����j�ʧA�ҷQ�n���_���C���訫
�i�H�^���D�W�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road7",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
