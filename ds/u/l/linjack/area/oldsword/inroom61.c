#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K��");
 set("long",@LONG
���}�F�t��, �A�~�o�{�̭����M�O���}��! �o�K�Ǥ���b
�t�����o�F, �ӥB�Ů�ܦ�, �Aı�o���I�ݤ��L���! �J�Ӭ�
�ݥ_������W��۩_�Ǫ�����.
LONG
    );
 set("exits",([ "east":__DIR__"inroom33",
                "west":__DIR__"inroom55",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
