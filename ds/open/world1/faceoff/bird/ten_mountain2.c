#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�s���s��"NOR);

 set("long",@LONG
�o�̬O�@�Ӥp�p���s���s��, ���ӬO�H�e���n�q�L�s����
�D���ȤH������, ���M�{�b�s���̹D�w�g�_�F, ���L�ӤQ�U�j
�s�ȹC���ȤH�٬O�۷�h��, �]���o�Ӥp�s�����M�^��������
�L�����ȤH����.
LONG
    );
 set("exits",([ "west":__DIR__"ten_mountain3",
    ]));
 set("objects", ([__DIR__"obj/pot" : 1,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
