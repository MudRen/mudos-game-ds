// Room: /open/world1/tmr/north_bar/entrance.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}�Ь}�f");
	set("long", @LONG
�o�̬O�j�}���}�f�A���̭��Q���w�R�A�s���w�ͳ��i�Hť��
�@�M�G���C���̭��ǨӰ}�}���˪��D���A���T���H�򰩮��M�A�p
�G�A�M�w�i�h�A�ȥ��n�Q���p�ߡA����ĵı�A���M�٬O���I���X
�}�f�a�I
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f1",
   "out" : __DIR__"town31",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
        ::valid_leave();
   
           if( dir == "out" && !userp(me) )
                        return 0;
        return ::valid_leave(me,dir);
}


