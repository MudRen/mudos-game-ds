#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"����"NOR);
 set("long",@LONG
�o�̽�۳\�h���~�A���񦳳\�h�H�b�ƶ��R�F��A�o�̪��F 
�����M�Z�K�y���A���~��o������I�p�G�A�Q�R�F��A�i�D�A�A
�i�H������������I

LONG
    );

       set("exits",([
       "east":__DIR__"town12",
       "west":__DIR__"town19",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
}     


