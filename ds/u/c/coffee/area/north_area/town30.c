#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�p��"NOR);
 set("long",@LONG
�o�̤Q������D�A�Ů�]�Q������A�]���o�̨ä������H��
�A���ɳo�̤]�|�Ǩӹ��O�r�~���q�n�A���T���H�P��Q���M�I�A
�ҥH�A�٬O����^�h����w���a�C

LONG
    );

       set("exits",([
       "west":__DIR__"town29", 
       "north":__DIR__"town31",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

