#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIC"�ɪž�����---A.D 2015"NOR);
set("long",@LONG
�A�@���i�o�̡A�o�{�ۤv���B�b�b�Ť��I�Ӹ}���U�O�@�s�H�A
��۵��R�A���b�j�n�w�I���I�o�O���^�ƩO�H�u������B�{�F
�@��r�A�]�\�ݬݨ��Ǧr(look word)�i�H�F�ѫe�]��G�C
LONG);
set("item_desc", ([
"word":@NOTE
�ϡE�� ���������~ �@�ɬF��������

�ҿת��Ĥ@�@��(first world)-�_���A�ڬw�A�Ȭw�a�Ϫ�
���פu�~��a�A�g�L10�~�Ӫ��V�O�A�ש�N�e�j���T����
�t�X�֡A���ߤF�ҿת�GB�AGolbal Market�A���y�����C
�åB�A�Q�η�ɤ@����Ǯa-���S�E�~��(Matt Hans)��"
���|�۪v"�z�סA�Q�n�������@�H�v�A���ʪ��|�p�e�A�M��
���k�߰�¦���ؼСC�Ӿ�ӭp�e�A�K�ѳo��~���դh�Ӿ�
���C
�z�L���p�X��(UN�AUnited Nation)�����s�k�e�A�ù�
�ҿת��ĤG�@�ɱj�v��a-Ĭ�p�A���꦳�Ī�ĳ�Ʊ���(�Y
��_�M�v����)�A�@�ɪ��s���Ǩ��{�F�C


NOTE
 ]) );
set("exits",([
"north":__DIR__"time3",
"south":__DIR__"time1",
]));
set("light",1);
setup();
replace_program(ROOM);
}

