#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"�t���w��"NOR);
        set("long", @LONG
�o�̬O�t���w�����~, �A�i�H�z�L�������������ݨ�
�t���w�𪺤W��, ��W�����C�a, ���𤺫K�O�k�v�̾ǲ߻P
��s�]�k���B��, �̭��Ҵ��o���j�j�]�k��q�ϱo�Z�H����
�P�����j�j���O�q

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "northwest": __DIR__"dst7",
            "southeast": __DIR__"dst1",
            ]));
 set("item_desc",([
           "����":"�t���w�𪺳���, �O�ǥѱj�j���]�k�O�q�H���`�۲զX�Ӧ���, �W���躡�Fĭ�õ۱j�j�O
�q���]�k�G�y, �ϱo����N�Ϲ�o�y��i��������H���|�D�����H�Q�����j�j����.\n",
"�t���w��":"�@�y���q�J�����]�k����, �]�k�v�̦b���ǲߨñ����շ�, �t���w��O�j�N�]�k�v�̥H��
�j�j���O�q�N�o�@�W�̨��]�O�����`�۲զX�Ӧ�, ��y��֦��j�j���]�O, �O�@�ۦ�b��
�����]�k�v��, �۶Ǧ���֦��j�j�]�O���·t�q���N�ϥH��j�j�����]�k�R����y����, 
���L���G�y�|���᧹�Y�Q���z�����^�S��(God of Wisdom-Interser)�����p���R���J��, 
�ݨ��o�y����P�ɤ]����ܤ֤@�쯫�骺�O�@.\n",
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
