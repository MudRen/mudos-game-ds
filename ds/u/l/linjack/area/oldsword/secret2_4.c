#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�A�Ө�F�@�Ӧ��Ѹ�, �E�ݤ��U���򳣨S��, �i�O�A�Y�J
�Ӫ��[��N�|ı�o�A�ҽ񤧦a�O�Ťߪ�, �@�w�O����K�D�αK
�ǩҦb���a, �ӥB�A�ٯ�ݨ�a�W���@�ӥ۶�, �۶������@��
�p��, �ݰ_�ӬO�n���_�ͤ~��}�ҳo�ӯ���.
LONG
    );
 set("exits",([ "east":__DIR__"secret2_3",
                "down":__DIR__":secret2_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
