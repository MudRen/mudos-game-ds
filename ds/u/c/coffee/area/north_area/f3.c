#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��"NOR);
 set("long",@LONG 
�o�̪��a�W�Q���W�Y�����A�ӥB�S�Q���U���A�a�W���O�d�g
���䳣�O���ťۡC�e�������n�������~���ʪ�����A�ݵۦa�W��
�}�L�A���A�q����쩳�O����Ǫ�...
LONG
    );

       set("exits",([        
       "northwest":__DIR__"f1",
       "southwest":__DIR__"f4",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}
