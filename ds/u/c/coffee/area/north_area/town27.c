#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�Z����"NOR);
 set("long",@LONG
�Ө�o�̡A�A�o�{��W���۳\�h�Z���A�M�B�j�B�C��������
�A���䦳�@�Τ��K�A���󥿦b���̥��K�A�p�G�A���ݭn���ܡA�i
�H����󻡭�I�n�ݻ��ت��ܽХ�(list)�C

LONG
    );

       set("exits",([
       "southwest":__DIR__"town26",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     


