#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�o�̬O�_�ٮp����_���A�P�ɤ]�O�]�a�����F�_��A��
�b�o�Ө��ר̵M�i�H�ݨ��b�s�������Ѿ¦b�s�p�W�͸ͪ���
�X�@�W���ϡA�i���o�̬O�_�ٮp���I�����A����X�G�w�g�P
ı����F.
LONG
    );
 set("exits",([  "northeast":__DIR__"ten23",
               "southwest":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

