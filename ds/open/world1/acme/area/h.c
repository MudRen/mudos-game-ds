// Room: /u/a/acme/area/h.c

inherit ROOM;

void create()
{
	set("short", "�}�Ѫ��p��");
     set("light",1);
	set("long", @LONG
�o�̬O�@�ӷQ��}�ª��Τl�A�w�ͤF�j����A�a�W�n���p�p���ǹ�
�٦��i�Q�E�λk�F�|�|�}�}����ȡA���G�����I�N���F�A���e���@���
�D���T�ܤ��i�����b�����W�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"pathway6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/taoist" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
