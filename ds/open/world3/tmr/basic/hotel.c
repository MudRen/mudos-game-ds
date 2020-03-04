// Room: /future/area/hotel.c

inherit ROOM;
void create()
{
	set("short", "�q�ϰs�]");
	set("long", @LONG
�o�O�@����j���s�]�A�]�O�o�ϰߤ@���s�]�A�O�o����u�H�b�@�Ѩ�
�W���u�@����A���|�ӳo�p�u�@�f�A�A���ɥiť��j����ǨӳټM�n�x��
�E�s�n�A�A�i�ݨ�s�]�ѪO���ˤ��a�M�ȤH��ѡB�ܰs�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	  "east" : __DIR__"digging_road1",
        "up" : __DIR__"hotel_2f",
	]));
               set("objects", ([ /* sizeof() == 1 */
                    __DIR__"npc/hotelrobot" : 1,
                      __DIR__"npc/li-r-ka" : 1,
               ]));
	set("world", "future");
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("no_magic", 1);
	set("light", 1);
	set("no_kill", 1);

	setup();
        call_other("/obj/board/tmr_future_b", "???");
}
