#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���G�t�Y"NOR);

 set("long",@LONG
�A�C�C������o�ǥ��r�������a�L��, �A�Pı��ۤv�����L�}�l�o�n,
���M�A�w�g�ɶq��C�A���}�B, ���٬O�����֤p�G�b�A�����Z�U�學�Ӱ_,
�åB���Y�F�������ݵۧA, �n���A�O�@�Ӱ����ƪ��p�Ĥ@��, �p�G���O�e��
�y���z�h�ղ�, �A�@�w�|�������h��o���p���V�N���p���I, �A�`�N����
�����}�f, �i�H���G�q�L, ���L�̥X�h�V��, �ӥB�o�̬۷���, ���ѤF�}
�n���ͬ�����, �o�]���ǳo�̷|������h���G�F, �i�O, �Ю{�̦p��Ķ���
�į�, �٬O����.
LONG
    );
 set("exits",([ "south":__DIR__"guild3",
                "north":__DIR__"guild5",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

