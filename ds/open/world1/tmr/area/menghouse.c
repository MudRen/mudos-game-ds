// Room: /u/t/tmr/area/menghouse.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", "�����a");
        set("long", @LONG
�o�N�O�s����������B�F�A�Τ��\�]²��A�V���B������Ҷ}�F����
��A�ӱo���ǩ��G�A�O�H���M��n�A��W�ٱ��F�@�T�Ѫk�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	  "north" : __DIR__"vroad1",
	]));
        set("item_desc", ([
	"�Ѫk" : "�@�T�ݨӻ���z�����Ѫk�A�W�Y�g�ۡu�A���ѤK���A�^���۲��Ρv�C\n",
	]));
	create_door("north","��O��","south",DOOR_CLOSED);
	set("objects",([
		__DIR__"npc/meng" : 1 ,
	]) );
	set("light",1);
        set("no_clean_up", 0);
        setup();
}
