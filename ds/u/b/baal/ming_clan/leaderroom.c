#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "�ХD�M�ζ�");
        set("long",@LONG
�o�O���Ф������N�ХD�M�Ϊ��ж��A�ѩ���бĥ���������A�ҥH
�o�̤]�N������j�ХD�K�ͪ��a�A�|�P�\���F�}�����Ϋ~�A��ֻs
���a��A�[�W�C�m�����Q�O���o�X�X�M���Pı�A��l�W�\���F�é_
�����A��������i�j�ɤW��۶I�ֻs�������A�ɤW���A�b�٥Ϊ�
��´���A�@�����I�R������H����C
LONG
        );
        set("light",1);

        set("exits",([
  "down": __DIR__"mingsaint",
]));
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
        setup();
}

