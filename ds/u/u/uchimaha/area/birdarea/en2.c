#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�{�b�i�J�F�F�_�A�L, �|�P������ϧAı�o�ܵ�
�A, �j��@�ʱ��ۤ@���q�ߵ�, �K���\�L�F�A���Y��,
�A�}�U���g�a��_���P�P�n�n��, �p���@�����۪F�_��
����U�h�C
LONG
    );
 
 set("exits",(["northeast":__DIR__"en3",
               "southwest":__DIR__"en1",
       ]));
 set("outdoors","land");
 setup();
}           
