#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���d�h��, �o�̪��a�W�����H�H��
�d�h, �ϧA�������, �A���ɻD��@�Ѩ�󪺯��, ��
�A�Pı���I�Q�R.

LONG
    );
 
 set("exits",(["east":__DIR__"en54",
               "west":__DIR__"en52",
               "north":__DIR__"en51",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
