inherit ROOM;

void create()
{
        set("short", "�a�U���J�f");
        set("long", @LONG
�o�̤@���I�R��D�A�ҿת�[ ���ӯ�� ]���ӫ����N�O�o�̤F�a�I�u
���|�g�@�@�������R���b�A�����ǡA�@�}�}�F�N���P�Y���ìV���Ů�a��
�u�u�����F�j�ӡA�����q�۰�b�o�����ҤU���㪺���G�P�öQ�A�b�}��
�䦳�@�Ӻ��ª��}�]�A�����D�q������[0;1m�[1mC[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 "down":__DIR__"sec1.c",
 "north":"/open/world3/tmr/basic/digging_road7.c",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("outdoors","future");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


