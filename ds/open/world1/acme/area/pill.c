// Room: /u/a/acme/area/pill.c

inherit ROOM;

void create()
{
	set("short", "�M�����E");
     set("light",1);
	set("long", @LONG
�A�@��i�o�̫Kı�Į𼳻�A�b���䦳�ө۵P�A�W���g�ۡy�M�ߡz
�G�Ӥj�r�A���ª��d�i�᭱�}�C�ۤ@�C���d�A���d���C�ө�P���ľQ��
�W�x�S�����󪺼��ҡA�譱��W���N���ȭ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"street6",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/herbalist" : 1,
]));
set("room_type","sell");        //�ө�(�u��R�F��)
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
