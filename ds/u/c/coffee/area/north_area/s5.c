#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�o�̬�M�]�X�ư����~�A�}�l�o�Ʀ����ç����A�I���A����
���ӹL�ӡA�[�W�a�W���d�h�a�A���A����ʧ�[�������G�F�A��
���D�O�_�ٯ�X���h�E�E
LONG
    );

       set("exits",([        
       "north":__DIR__"s6", 
       "west":__DIR__"s9", 
       "east":__DIR__"s10",
       "south":__DIR__"s2",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

