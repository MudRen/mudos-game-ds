// Room: /u/t/tmr/area/lake-road1.c

inherit ROOM;

void create()
{
        set("short", "����p��");
        set("long", @LONG
�@���u�۴��䪺�p���A���δ¤Ѵ򪺪e�ɥ۶��ҾQ�]�Ӧ������A���}
���W�h���Pıť�������@�C�Ѧ��V�_���h�A�i�����ݨ�¤Ѵ򪺪F�b
���A�u���򤤤p�࿺�աA�ĵٺq�n�~�~�A�]���ཬ�C�H�A�e��­���춰�F
�W�U�@��A���P�O�H�Ĭ��[��C���F���@���ե۶�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
	   "eastup" : __DIR__"lake-road2",
           "northwest" : __DIR__"day_lake",
	]));
	set("outdoors","land");
        set("no_clean_up", 0);
	set("no_map",1);
        setup();
        replace_program(ROOM);
}
