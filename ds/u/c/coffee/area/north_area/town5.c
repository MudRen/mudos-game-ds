#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG 
�b�o�̥i�Hť�컷��ǨӪ��s���n�A���ӬO�o���񪺰ө���
�u�c�a�C���L�A�o�̪��Ů��b�Ӱ���F�A���A�Ԥ���}�lı�o
�f���A�u���e�����@�f�j���A�A�]�\�i�H�L�h�ݬݦ��S�����ܡI
LONG
    );

 set("exits",(["north":__DIR__"town6",
               "south":__DIR__"town4",
               "west":__DIR__"town10",
               "east":__DIR__"town11",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        

