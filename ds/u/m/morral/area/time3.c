#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIC"�ɪž�����---A.D 2020"NOR);
set("long",@LONG
���Ӫ����v�@���@�����i�{�b�A�����e�A�A�ݨ�F���֤H�I�g��
�����W�A��������A�ӲĤT�@�ɪ���a�H���o���_���b�Ⱦj�P�Ǹo��
���u�A���O�L�̰�a���F���٦b���F�@�v���Q�q�ӪP�U�ۤv��a����
���I�ݬݨ��ǯB�{�b���䪺�r(look word)�i�H��F�ѫe�]��G�C
LONG);
set("item_desc", ([
"word":@NOTE
�ϡE�� ���������~ ���y����

21�@�������b�H�����o�i�U�A�w�g�ͩ�L���e�j�����H����A
�åB�ϥκ����ͬ��A�����X�᪺�H�w�j���H�b�C�]���A�F���Q
�ΤF��ɤw���񧹦��������y������(Global Market)�[�J��
�����A�Ǧ��ӱ����Ӻ������귽�C��M�A�o�]�y���F"�I��
�V�I�A�h�̶V�h"���{�H�C�p�ĤT�@�ɡA�o�ǹ�Ĥ@�ĤG�@�ɨ�
���A�i���O�����S���v�T�O�A�ڥ��b�@�ɤW�N�O�H�C�W���L��
�v���B���F�ȡC�]���p���A�b�p�X�ꤤ�u��H�ۥѸg�٪�����
�M�S�w��a�i��T���F�ӥ��y������O�����i�k�C�Ӧb���ߥ@
�ɬF���ɡA��ñ�q�U�����y�]�I�������t�A�y���g�٧��ժ���
�w�A�b�{��U�C�Y�F�E�E�E�E�E

�o�ɡA���S�E�~���b�@�ɤW�إߤF�۷��v�T�O�A�ש�b����
�����~���ߤF�~���]��(The Hans)
NOTE
 ]) );
set("exits",([
"north":__DIR__"time4",
"south":__DIR__"time2",
]));
set("light",1);
setup();
replace_program(ROOM);
}


