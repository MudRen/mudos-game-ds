#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG 
�A�~�򩹥_��, �|�P�����S�������h�F�_��, �åB���~
��, �o�Ǿ�쪺�~�֬ݰ_�Ӱ_�X�]���W�ʦ~�F, �o�������F�_
�����U�h.
LONG);
 
 set("exits",(["northeast":__DIR__"en75",
               "south":__DIR__"en72",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

