// Room: /open/world1/tmr/dragoncity/hotel2f.c

inherit ROOM;

void create()
{
	set("short", "�Y�s�ȴ�-�G��");
	set("long", @LONG
�o��O�Y�s�ȴ̪��G�ӡA�ѩ�֫ӭx�b�o�B�x�L�A�ҥH�o���ȴ�
�����F�n�[�J�֫ӭx�����ӫC�~�A�]�����֪Z�L�P�D�b�o��ܰs���
�C�u���H�n���_�����A���a���o�J�Y���B�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xuan-yong" : 1,
  __DIR__"npc/ma-ruo" : 1,
]));
      set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/xuan-yong" : 1,
    __DIR__"npc/ma-ruo" : 1,
  ]));


	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"hotel",
  "up" : __DIR__"hotel3f",
]));

	setup();
	replace_program(ROOM);
}
