#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������O");
 set("long",@LONG
�q�o�䩹�����h, �i�H�M�����ݨ�ʦ~�ӳ��@��
�z�ߤ��n���V����, ���W���X�������D�O���򳾦b�L��,
��, ���~�j�z���W���G�w�g���n�X�~�S���Ԫ��F.
LONG
    );
 set("exits",(["east":__DIR__"inroom58"]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
