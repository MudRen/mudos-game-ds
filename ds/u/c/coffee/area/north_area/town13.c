#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG
�o�̪��k��O�����a�����f�Ať���������H�ܵ��}�A���O��
��o�n��������дo���Ʊ��A��B�A��H�����C����O�@�f���A
�p�G�A���ݭn���ܡA�i�H�h���̶����C

LONG
    );

       set("exits",([
       "north":__DIR__"town15",
       "west":__DIR__"town6",
       "east":__DIR__"town20",
       "south":__DIR__"town11",           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

