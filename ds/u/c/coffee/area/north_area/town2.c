#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"�J�f"NOR);
 set("long",@LONG 
��A���}��i�j���ɡA�`�l�@�f��A�믫��M�n�F�_�ӡA�o
�̪��Ů�u�O�s�A�C�A�|�B�i��A�oı�o�̪��H�Q��������n��
�A�ݫȤ]�Q�������C�A��M�o�{�A�����̪��H�̬諸��A����A
�Ҩ��L����A�������@�ˡA�A�߷Q�G�o�̯u�O�S�O�E�E�C
LONG
    );

 set("exits",(["north":__DIR__"town3",
               "south":__DIR__"town1",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
