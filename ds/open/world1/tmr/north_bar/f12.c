// Room: /open/world1/tmr/north_bar/f12.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�}��");
	set("long", @LONG
�Ө�o�̡A�u���M�Q���·t�A���A���G�Pı��e���n�����@
�Ѩ���A�צ�A���h���A�p�G�n�g�L�o�̡A���G�n�M�L�@������
�I�_�h�u�n���^���F�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"f11",
  "down" : __DIR__"s1",
  "northwest" : __DIR__"f10",
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
}

int valid_leave(object me, string dir)
{
   
        if( dir == "down" && !userp(me)  )
                        return 0;
        return ::valid_leave(me,dir);
}
