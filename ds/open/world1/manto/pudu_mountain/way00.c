#include <ansi.h>

string *mountain_msg = ({
"���a�B��`�s�����A���[�R���W���j�Q�A�b�������������{\n"
"�A�ϩ��O�����P�H���~�ҡA�O�H�椧�ͷq�C" ,
"�H���\\�D�W�~�k���s����A�����a���񰪳B���x�ӡA�X����\n"
"���ƤF�L�ӡA�N�H�]�Цb�@���կ����A��O���˶��r�����Pı�C" ,
"�k��F���B�A�s�������W�i�@��̹D�C�u�۴̹D���W�s�A��\n"
"�F�����Q�����A�u���D���V����s���A�V�O�U���A�����]�V�O��\n"
"�V�����C" ,
});

string *outdoor = ({
HIY"\n    �s���v���j�F�_�ӡA�I�I���j�ۡA�Q�w�p���w�르�b��H�y�W�C\n"NOR,
MAG"\n    ���S���@�I�����N��A���ѱo���H���ԷV���b�̹D���樫�C\n"NOR,
WHT"\n    �����۪����h�A�p��y��N�s�Y�������]�ۡC\n"NOR,
CYN"\n    �ѤW�Ƶۦp���������A�P�a�W���⤬�۩I���C\n"NOR,
HIC"\n    �s���p�B���X�w�w�a�U�ۡC\n"NOR,
HIC"\n    ���p�ǤF�A�Ů𤤳z�ۦB�N���𮧡C\n"NOR,
});

string print_mountain_msg() 
{ 
    return mountain_msg[random(sizeof(mountain_msg))] + outdoor[random(sizeof(outdoor))];
}

