#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�_����");
 set("long",@LONG
�q�L�F�T�W�u��, �A�Ө�@�Ӥs�_����, �o������F
�A�@�Lť�D�����_���, ���ۤ]�Q���_�S, ���O�̭����T
�|�W�����Ŧ窺�����H������A�������ݵ�, �L�̦��G�O
�t�d���U�o�̪��H, �A�̦n���I���}. �o��T�����O�s��
���H�����o�{�o��.
LONG
    );
 set("exits",(["south":__DIR__"garden1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
