#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p��");
 set("long",@LONG
�A�~�򩹪F��, �o�̪������j���S�����ܤ�, �Aı
�o���ǵL��, ������ı���j�_�f��_�ӤF, �A�j�_�F�j
�a�ռ���Ԫ���q, �A�{�b�~�ݨ�o�����@���q���_��
�����B.

LONG
    );
 
 set("exits",(["north":__DIR__"en45",
               "west":__DIR__"en43",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
