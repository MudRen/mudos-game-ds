// Room: /u/t/tmr/area/s_house.c
#include <room.h>
#include <path.h>

inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "�۫Τ�");
        set("long", @LONG
�o�O�@���Υ۶���n�Ӧ����@���p�ΡA�Τ���ȤL�f�ҥΦ˽s�Ӧ��A
�u�]�@���@���A���]����²��C�Ӭݦa�O�ۿj���Ҧ��}�L�A�`�Ψ�o�A�|
��������G�p�}�A�ݯ}�����C
�F��W�������B�A�W�Y�g�۫ªZ���@�y�ܡG�u�A���ѤK���A�^���۲��Ρv�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"glade",
   "west": TMR_PAST"bagi/rift",
]));
        set("no_clean_up", 0);
	set("valid_startroom",1);
	set("objects",([
	__DIR__"npc/master" : 1,
	]) );
	set("light",1);
        setup();
      create_door("west", "���", "east", DOOR_CLOSED);
}
