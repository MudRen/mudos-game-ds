#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG 
����A�L��A�o�̶��}�ɡA�o�{�\�h�s�_�����N�A���䪺��
�l�B�ؿv���Q���S�O�A���ǩЫάݰ_�ӫܷs�A�����Ǭݰ_�ӫo�Q
���}�¡A�s�Τ��Y����������Q�γE���F�C����]�\�h���񪺤p
�Ĥl�b�o�̪��A�C
LONG
    );

 set("exits",(["north":__DIR__"town4",
               "south":__DIR__"town2",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
