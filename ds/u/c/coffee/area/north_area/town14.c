#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG
�Ө�o�̡A�A�oı�P��}�l�����F�A�ӥB���춧���Ӯg����
�n�}�l��֤F�A��_�䦳�����㩱�A�p�G�A���ݭn���ܡA�]�i�H
�h����ݬݡC

LONG
    );

       set("exits",([
       "northwest":__DIR__"town16",
       "east":__DIR__"town7",
       "south":__DIR__"town12",           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

