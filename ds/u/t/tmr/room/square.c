// Room: /u/t/tmr/room/square.c

inherit ROOM;

void create()
{
	set("short", "�����s��");
	set("long", @LONG
�o�̬O�_�a�������s���M�@�襨�j���Ѻ_��L�ڿ����a���b����
�M�@�ǫĵ��`�`���W�o��Ѻ_�^���M�_��U�C��K�ݦa��۴X�i������
�H������ѡM
LONG
	);
	set("light", 1);
	set("current_light", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "�Q�����q�`���������M�p�G�A�֤F�M�����Ȯ�M�ɺް��U�ӥ𮧡C

",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : "/u/t/tmr/workroom",
  "enter" : __DIR__"room1",
]));
	set("no_clean_up", 0);

	setup();
        call_other("/obj/board/tmr_b", "???");

}
