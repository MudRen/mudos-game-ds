#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�o�̦��G�Z�w�R�a�A���k��N�S�����F�C���O�@�ˬO���Ǫ�
�b�]�Ӷ]�h�A�ӥB�a���٫���n�̵ۡA���H�Pı�Q�����w�A�|��
�|����@�b��M��Ӭ}���U�ӡE�E
LONG
    );

       set("exits",([      
       "west":__DIR__"s7",   
       "south":__DIR__"s14",             ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

