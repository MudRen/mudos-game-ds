// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"�D�㩱"NOR);
	set("long", @LONG
�o�Ӱө��M�����ѦU�خȦ�Υ��ɩҭn�Ψ쪺�u��ιD��A�y�u����
��ơA�����Q�侹�C�z�O�o�a��������̱`�����@�y�ܡC�A�|�ݭn���̪�
�C��W���ӧi�ܵP(note)�C
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
	set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"room063",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}