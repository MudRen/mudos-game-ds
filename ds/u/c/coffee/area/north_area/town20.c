#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�����a���f"NOR);
 set("long",@LONG
�o�̬O�_�Z�������a���j���A�A�S�Q������a�~�M����
�j�A��@�몺��v�j�W�T���A�A���T�Q�i�h�}�}�A���O�H�K
�i�h�u���n�ܡH

LONG
    );

       set("exits",([
       "west":__DIR__"town13", 
       "east":__DIR__"town21",           ]));

        set("objects", ([
           ])); 
 set("outdoors","land"); set("no_clean_up", 0);
 setup();
}     


