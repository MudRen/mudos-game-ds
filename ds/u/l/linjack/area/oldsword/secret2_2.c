#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e���f");
 set("long",@LONG
�o�䦳�T�����������u, �q�F�_��ﭱ�j�Ӥ@�ѧN��, �ө��F��
���G�٦��@���ܪ�����. ����n���h����շt, �ݤ��M�����p.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_3",
                "southwest":__DIR__"secret2_1",
                "east":__DIR__":secret2_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
