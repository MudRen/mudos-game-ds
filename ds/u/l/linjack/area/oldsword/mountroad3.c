#include <room.h>
inherit ROOM;
void create()
{
 set("short","���V���󪺤s��");
 set("long",@LONG
�A�b�s���}�}��������L������F�n�@�}�l����, �`���F
�@�B������m���a��, �o�䪺���w�g�e�s�h�F, ���O��Ǥ��O��
���֪����צ��誺����, ���L�A���D�ѤU�Ӫ��o�q�s���w�g
���|�ܪ��F.
LONG
    );
 set("exits",([ "northup":__DIR__"mountroad2",
                "west":__DIR__"mountroad2_1",
                "southeast":__DIR__"mountroad1_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}