#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"���d��"NOR);
 set("long",@LONG 
�o�̫e�����@���J���q���e��A����Ǫ��۾��Q�����q�A��
�o�o���D�J�ݰ_�ӤQ�����U���A�ӥB�o�̪���]�}�l�S�������
���A�}�lı�o���I�ǩǪ��C
LONG
    );

       set("exits",([
       "north":__DIR__"town9",
       "south":__DIR__"town7",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}     
