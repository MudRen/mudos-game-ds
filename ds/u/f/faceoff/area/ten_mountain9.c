#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�s���_��"NOR);

 set("long",@LONG
�o��N�O�s���̹D���_���B�F, �q�o�̥i�H�ݨ��s������
�����_����q, �]�]���o�����_�F, �B�s���̹D��x�����Q�q
�èS���w�Ƥ����j, �ҥH�]�N������o, �����t�@�ݴN�O���
�V�F, �A�b�Q�Ӥ��|�����ӺƤl�Q���L�ۭ�������賓�a? ��
���^��, �A������ˬO���@�a�ȴ�, �]�\�A�i�H�i�h�ݬ�.
LONG
    );
 set("exits",([ "south":__DIR__"ten_mountain8",

               "west":__DIR__"hotel1",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}
