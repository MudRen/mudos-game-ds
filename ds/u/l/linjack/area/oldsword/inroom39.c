#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������O");
 set("long",@LONG
�o�ӥ��O�~�O��������ӦV���󪺥�����, �A�����U��
�ݹL�h, �|�o�{���ӥ~�����@����o�o���γ����! ���M�o�Z
���H�m�H��, ���L�ƹ�o�\�b�A���e. �o�䦳�@��Ӧu��b��
�y�ݦu.
LONG
    );
 set("exits",(["east":__DIR__"inroom37",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
