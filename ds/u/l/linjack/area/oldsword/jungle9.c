#include <room.h>
inherit ROOM;
void create()
{
 set("short","�h�A��");
 set("long",@LONG
�A�̵ۧA���}���\�ҫj�j������F�h�A������, ���w�g�V�ӶV
�`�F, �ӥB�o�h�A�̤����D������M�I, �A�̦n�O�����}����w��,
�n���M��ɫ�Y�ۥX�ӧ��]���ǧA�N�o�I�ѷm�a�F.....
LONG
    );
 set("exits",([ "west":__DIR__"jungle10",
		"south":__DIR__"jungle8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}