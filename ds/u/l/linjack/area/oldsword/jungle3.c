#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�o��ݰ_�ӳ��˴˪�, ���Aı�o�������ۦb, �ӥB�A�`�O�b
��߷|�_��M���r�~�X�{�ӧ����A....�Aı�o�٬O���}�o����
�b�o��n�Ӫ��n�h�F......
LONG
    );
 set("exits",([ "east":__DIR__"jungle4",
		"south":__DIR__"jungle2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}