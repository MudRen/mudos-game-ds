#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"��D"NOR);
 set("long",@LONG 
����o�̡A����X�G���O��a�~������v�C�e��]���@�ǥ�
���B�ө����A�Q�����x�C���O�o�̪��a�O�o�����O���g�B�٦��@
�Ǥp�ۤl�C�[�W�o�̤Ѯ�Q������A���A�}�lı�o�f���F�C
LONG
    );

 set("exits",(["north":__DIR__"town5",
               "south":__DIR__"town3",
           ]));

 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}        
