#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�x�|"NOR);
 set("long",@LONG
�o�����M�]�O�x�|�A���ɫo�S������A�u�k�@������
�M�@���ý��A��e�誺���u�����צ�F�A�����D�e��O����
�F��A���T���A�Q���n�_�C

LONG
    );

       set("exits",([
       "south":__DIR__"town23",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

