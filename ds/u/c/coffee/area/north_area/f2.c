#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��"NOR);
 set("long",@LONG 
�o�̪��a�W�Q���W�Y�����A�ӥB�Ѫ�O�S�Q���U���A�@���p
�ߴN�|�����Y�C�b�o�̡A�A�}�l�J��F�@�Ǭݰ_�ӤQ���z�p����
�~�A�@���`�N�A�e�N�|�ĹL�Ӱ�ŧ�A�A�аȥ��p�ߡI
LONG
    );

       set("exits",([        
       "northeast":__DIR__"f1",       "southeast":__DIR__"f4",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

