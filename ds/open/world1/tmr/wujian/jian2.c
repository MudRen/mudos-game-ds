// Room: /open/world1/tmr/wujian/jian2.c

inherit ROOM;

void create()
{
	set("short", "�ŵL��");
	set("long", @LONG
�L���O��жǻ����Ҵ��쳡���H����Ҩ쪺�a�����A�D�k�̴ݻ�
���@�ӡC�m�I�L�g�n�ĤQ�E���u�K�j�a�����̡A�٬��L���a���A���L
���_�D���j�W���N�A�G�����W�v�F�L�����T�G�ɵL���A�ŵL���A���~
�L���A�Ǥ��E�o�̥üZ���ɡA�ɨ��׷����L���C�o�䪺����D�`�@�A
���H�Ѫ��A�I�����I�R�n���A�V�[�Y��X�A���ߪ����ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"snake-room6d",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
