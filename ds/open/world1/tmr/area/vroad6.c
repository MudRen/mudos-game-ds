// Room: /u/t/tmr/area/vroad6.c

inherit ROOM;

void create()
{
        set("short", "�p�Ѥl");
        set("long", @LONG
�@�����t��ê��p�Ѥl�A���ɥiť���Ѥl���ҶǥX���X�n���s�A�uı
�o�|�P���𭫭��A�O�H�����o��A���Q�[�ݡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "northeast" : __DIR__"vroad4",
]));
	set("objects",([
 	  __DIR__"npc/vag" : 1,
	]) );
          set("light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
