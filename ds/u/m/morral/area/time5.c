#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIC"�ɪž�����---A.D 2080"NOR);
set("long",@LONG
��Ӧt�z�{�b�N�b�A�}�U�A���O�A�o�P��@�}���Ԫ���^�C
�H�������ӬO���������t�鬤��A�[�[�����C�ݬݨ��ǯB�{�b��
�䪺�r(look word)�i�H��F�ѫe�]��G�C
LONG);
set("item_desc", ([
"word":@NOTE

 �ϡE�� ���������~ �P�ڶ}�o

�p�X�ꤺ�]�ߪ��p�X��ӪŬ�s����(UNSRC�AU�EN�E Space Reaearch 
Center)����Ǯa�b�o�X�~�o�{���¬}�X�{�b�Ӷ��t�ǡA���O�ҵo�{��
�ä��O�u�����¬}�A�ӬO�@�خɪŸ��D�I(SJP�ASpace Jumping Point)
�o���ɳy���F�۷�j���_�١A�n�DUNSRC�ɧֱ����������P��A�H�θ�
�a�y�H�f�z�������D�C
�|�~��AUNSRC�����سy����β����ӪŲ�A�ӷ�ɭt�d���A�O�p�J�E�h��
�դh(DR�ERax Whites)�C
�S�L�F��~�A�bUNSRC�զ���D�ɪŦ��\���@��G�ӷs�P�t�A�N���y��
�����a��F�̰��W�A��M��ɤw�g���j���~���]�Τ��|��L�o�ӥi�H��
���H�����޳N�A�۵M�}�l���lUNSRC�M�h���դh�C
���h���դh�èS������e���}�A�A�L�n�����Q�Ψ�L��a�ѻP�Ӫŭp�e
�ӧ���ɹ�ڤW�b�F�v�M�x�O���w�b�U�ꤧ�W���~���]�ΡC�åB�h���դh
�]�Q�Ψ�������F�v��O�A�N�H�ߩM���ߤ��_���ݮi�}�ӡC
�ӥ���H���V�������t�z���X��������ɡA���Ӱ��D���b���C�ۡA�N�O��
�Q�~�ӤH���믫���`���H�Ƥj�T�W�[�C
�������̱N���ƴ��X�ӡA���o�Q�w�g�K�ڦb�I�Υ��w���p�X�ꥸ���L�]���͡A
�åB�źٳo�u�O�]�a�y�H�ƹL�h�A�u�n�Ӫŭp�e���\�A�N�i�H�ѨM�������D�A
�]�I�~�ɶq�������y�A�H��֤H�f���O�C

NOTE
 ]) );
set("exits",([
"north":__DIR__"time6",
"south":__DIR__"time4",
]));
set("light",1);
setup();
replace_program(ROOM);
}

 
 
