// Room: /u/k/kenshin/sha-zin-gu/room17.c

inherit ROOM;

void create()
{
	set("short", "[33m�E�s�ȴ�[0m");
	set("long", @LONG
�v�騦�̰ߤ@���ȴ̡A�@�i�h�N�D��ιD�a���s�g���Ҳi�ժ�
���s���L�Ať����W�٦��H�ʬr�������G�ҽզ������G�s�A���O��
�D�n���٬O���ȴ̩��p�G���ˤ��۩I�A���Hı�o�b�o�̶R�F��O�z
�ҷ�M���C
LONG
	);
	set("room_type", "hotel");
	set("no_fight", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/waiter" : 1,
]));
	set("current_light", 3);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room18",
  "east" : __DIR__"room16",
]));
	set("valid_startroom", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
