#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG 
�o�̬�M�ܦh�H���֦ӨӡA��ӬO�b�m�ۨ����̪����A�]
���o�̬O������H�N���ꪺ�a�ϡA�����۷��e���A���̪���
�����a�����ߤ@�����ͬ��A���M�n�����N�n�Q���·СC
LONG
    );

 set("exits",(["north":__DIR__"town7",
               "south":__DIR__"town5",
               "west":__DIR__"town12",
               "east":__DIR__"town13",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        


