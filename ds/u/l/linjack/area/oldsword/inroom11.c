#include <room.h>
inherit ROOM;
void create()
{
 set("short","�[�Ƕ�");
 set("long",@LONG
�A���F������h�Ӱ����˱�, �ש�Ө�F�o�ӦV�����Ӥ��@���[��
��, �]���o�O�M���������[���Ƕ��������n���⪺�@�Ӱ���, �ҥH�]
���G�m�F�p��p��, �ѻ��Ȯy�ۦn�n�~��, �[�歷��. �������~, ����
�~���{�U, �]�i�H���V���󪺤H�����o�{�~�ĤJ�I, �ҥH�]���@���@��
�b���ݦu��.
LONG
    );
 set("exits",([ "down":__DIR__"inroom6",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
