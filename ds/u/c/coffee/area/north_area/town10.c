#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG 
�o�̤Q�����x�A��B�R���F���x���n���n�A���p�Ī������n
�A�]���q�����ǨӪ��s���n�A�e�������B���@�f���A���̤]�E��
�ܦh�H�A�]�\�����򦳽쪺�ơE�E

LONG
    );

       set("exits",([
       "north":__DIR__"town12",       "east":__DIR__"town5",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}     
