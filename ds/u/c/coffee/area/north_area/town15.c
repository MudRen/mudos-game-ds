#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG
�Ө�o�̡A�A�oı�P��}�l�����F�A�ӥB���춧���Ӯg����
�n�}�l��֤F�A�F�_�䦳���Z�����A�p�G�A���ݭn���ܡA�]�i�H
�h����ݬݡC

LONG
    );

       set("exits",([
       "northeast":__DIR__"town26",
       "west":__DIR__"town7",
       "south":__DIR__"town13",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

