// Room: /open/world1/tmr/north_bar/s1.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�a�U�G�h");
	set("long", @LONG
�o�̬O�j�}���ĤG�h�A�u�S�Q��A�o�Ӷ·t���j�}�A���M��
�����h�A�ӥB�o�̦��G�󮣩ƤF�C����ǨӰ}�}�����~���G�s�n
�A���G�O���~�b���ۦ۴ݪ��n���C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"s2",
  "up" : __DIR__"f12",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
   
        if( dir == "up" && !userp(me) && me->id("monster") )
                        return 0;
        return ::valid_leave(me,dir);
}
