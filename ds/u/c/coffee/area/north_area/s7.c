#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��-�G�h"NOR);
 set("long",@LONG 
�o�̪��a�O������|��ƤF�A���O�ۤϪ��a���o�_�ʱo��F
�`�F�C�e���i�H�ݨ�@�ӥΥۿj�سy�Ӧ����p�ж��A�����D�̭�
������_�S���F��A�Ϊ̬O�S����M�I�����~�H
LONG
    );

       set("exits",([        
       "north":__DIR__"s18", 
       "west":__DIR__"s16", 
       "east":__DIR__"s17",
       "south":__DIR__"s6",           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}

