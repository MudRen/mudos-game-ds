// Room: /u/a/acme/area/pathway4.c

inherit ROOM;
void create()
{
	set("short", "�p�|");
	set("long", @LONG
�o�̬O�@���p�|�A�]���[�H��u�ܡA�����O�͡A������ť�쳥�����p
�s�n�A�p�|���F�䩵���ӥh�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" : __DIR__"pathway5",
     "northwest" : __DIR__"pathway",
    ]));
        set("no_clean_up", 0);
      set("outdoors","land");
      setup();
      replace_program(ROOM);
}   
