// Room: /u/a/acme/area/weapon.c

inherit ROOM;

void create()
{
	set("short", "���K�E");
     set("light",1);
	set("long", @LONG
�o�̬O�@���p�p�����K�Q�A�K�K���ۥ��K�u��b���l�ǺV�V�������A
���l�M�X�A���v�l�b��W�@�̤@�̪��A�A�Pı��o�̥X�_�����A��������
�O�v�C����h�i�X���K�Q�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"plaza2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/smith.c" : 1,
]));
set("room_type","sell");        //�ө�(�u��R�F��)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
