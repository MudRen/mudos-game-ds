// Room: /open/world1/tmr/area/mouse_hole.c

inherit ROOM;

void create()
{
	set("short", "���}");
	set("long", @LONG
�A���b�@�Ӭ}�̡A���G�O�ѹ����X�Ӫ��}�A�i�O�}���Ŷ��e�s�A�N��
�A�h�ӴX�ӤH�]���|ı�o�����C�A�o�{�|�P���K���߮�v�v���N���ܡA��
�^�Q�����x���ɡA�۷��L�~���Pı�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"inn_3f",
]));

         set("objects", ([ /* sizeof() == 1 */
                  "/open/world1/tmr/game/2008_year/npc/simon" : 1,
//                 "/open/world1/tmr/game/2008_year/npc/alvin" : 1,
                "/open/world1/tmr/game/2008_year/npc/theodore" : 1,
                "/u/t/tmr/game/2008_year/board" : 1,
          ]));
	setup();
	replace_program(ROOM);
}
