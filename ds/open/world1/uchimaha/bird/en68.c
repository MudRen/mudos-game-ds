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
 
 set("exits",(["west":__DIR__"en67",
               "southeast":__DIR__"en71",
               ]));
 set("objects",([__DIR__"npc/frog" : 3,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
