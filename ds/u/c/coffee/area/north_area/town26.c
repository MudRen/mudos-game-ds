#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�Ѥl"NOR);
 set("long",@LONG
�Ө�o�̡A�A�o�{�e�����a�Z�����A�q�o�̴N�i�H�ݨ��Z��
�{�{�o���A�A���T�Q�i�h�}�}�A���O�p�G�i�h�}�F�A�N�n�a�I��
�A�R��Z���a�I

LONG
    );

       set("exits",([
       "northeast":__DIR__"town27",
       "southwest":__DIR__"town15",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     


