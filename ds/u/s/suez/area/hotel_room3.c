// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "���");
	set("long",@LONG 
����ɦܡA�ʤt��e�A�A�@��J�o�̡A�Nť������n�A���F�����
�m�몺�r���A���~�]�H�˺ޤޤ��J�ǡA�����Ӭy�N�b�A���}�U�A�@�Ӥp��
���b�A������Ӥ����A�ӧ���U�N�����A����𤣷|���򪺭��A�]�ϧAı
�o�ξA�嶮�C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "south" : __DIR__"hotel_two",

              ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}