#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"���㩱"NOR);
 set("long",@LONG
�Ө�o�̡A��Ǫ�����W���۳\�h����A�����{�{�A�e���N
�O�d�i�A���󥿯��A���̡A�p�G�A�ʤ֨��㪺�ܡA�N�R�X�󨾨�
��A�����@�U�a�I�I�n�ݻ��ت�Х�(list)�C

LONG
    );

       set("exits",([
       "southeast":__DIR__"town16",
           ]));

        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

