#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K�L");
 set("long",@LONG
�o�̪��K�LŢ�n�F�A����ӵ���, �|�P��𸭷n���M���F�j��
���n���Z�äF�A��ťı, �A�ϩ��b�@�ӧ����S����쪺�a��. ���H
���i�H�ΤW�U�Y�ӧP�_�A����V, �֪��D�o�̪��a���O�ӥ��x! �u
�����D�V����|�ئb���Ӯ��ƪ��a��.
LONG
    );
 set("exits",([ "west":__DIR__"forest5",
                "south":__DIR__"forest4",
                "east":__DIR__"forest3",
                "north":__DIR__"forest6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}