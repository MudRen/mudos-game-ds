#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
�o�z�O�������A���U�|�P�A��ӳo�̴N�O���W����H�[�����СA��
�ǽݥߤ@���Ӥj���۸O�A�W����D�G�i���Z�L�֤H���A�ߧ�
���пW�B����C�j�e�観�@�y�I�R��Ӫ��c���A�W���g�ۡi�t���c
�j�T�Ӥj�r�A���гХߦܤ��w���G�Q�h�~�A��U�Q�X�U�Ю{�M���U
�a�O�Z�L���Ƥ@�ƤG���j���A�Q�����Щw�O�ת����s�A���ⶳ����
�a�C
LONG
        );
        set("light",1);
        set("exits",([
  "east": __DIR__"saintming",
]));
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
        set("ming_club_out",1); //���ХX�f
        setup();
}

