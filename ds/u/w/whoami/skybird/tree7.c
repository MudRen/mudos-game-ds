#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","�p�|");
 set("long",@LONG 
���e�g�a�@���, �j���O�k���䨺�ʰ��q�ﶳ���j��B��
�F����, �ϱo�o�̤o������, ���O�]�]���o�ʤj�𪺧Ȧ�, ����
���b�o�̪��p�ʪ���K�󭸸V������.
LONG
    );
 set("exits",([
     "south":__DIR__"tree5",
     "enter":__DIR__"house",
             ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("enter","�}�ꪺ���","out",DOOR_CLOSED,"nokey");
}


