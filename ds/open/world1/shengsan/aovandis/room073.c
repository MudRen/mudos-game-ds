// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�a�ϩ�"NOR);
	set("long", @LONG
�o�̦��J�L���j���j�����a�ϤΫ������a�ϡA�A�`�N��|�P����W��
�����F��o���a�Ϩ��b�A�C�@�T�a�ϳ����Ժɪ��a�z���Ҥ��СA�u���O��
�W�ҭȡC�p�G���ݭn�A�i�H�V����R�C�ε۬ݬ���W���i��(note)�C
LONG
	);
	set("item_desc", (["sign":@NOTE
[1;32m
�G�i�P�W�g��:

		buy       �V����R�F��
		list      ����|�i�D�A�o�̽�Ǥ���
		value     ����|�i�D�A��o��F��L�|���A�h�֪���
		sell      ��Y�ӪF��浹����
[m
NOTE
        ]) );
	set("exits", ([ /* sizeof() == 1 */
	    "north": __DIR__"room019",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}