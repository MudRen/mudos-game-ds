#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");
 set("long",@LONG
�A�{�b�����b�@���C�۪O���W�A�Y�Ϧb�o�ضm�������A
�o���D�����«O�����۷�}�n�A�s�@���}�H���۪O���ݤ���
�A�i���o�b�a�H�۷��O�@�o���D���A�P�ɧA�]�i�H�ݨ���
�観�@�y���x�A�o�̤]���@�y�ѭ����һs�����Ǧ��J���A�q
�~���ݨӡA�o�O�@�������~�H���r��....
LONG
    );
 set("exits",([   "west":__DIR__"ten9",
               "east":__DIR__"ten5",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

