#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�ѹ��۫�"NOR);
 set("long",@LONG
�o���۫Ǹ̦��L�ƭӬ[�l, �[�l�̪��C�@�泣���@���ħ�, �ݨӳo��
�O�ѱ��x�s�ħ����a��F, �C�Ӭ[�l�W�����Ī��W��, �A�i�H�b�o�̧��
�ۤv�n���ħ�, ����, �b�ж����������ӤH���b��, ���G�O�b�ݦu�o����
��, �H�K�Q�~�H������, �ݨӧA�O�n�Ǹy�]�R�ħ��F...
LONG
    );
 set("exits",([ "north":__DIR__"guilda",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
