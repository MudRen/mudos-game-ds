// ���Z�}��

// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���㩱"NOR);
	set("long", @LONG
����O�A�b�԰������i�ίʪ����n�˳Ƥ��@�A���B���A�A�����b���J
�L���j���W�ҳ̤j�����㩱�̡C���ܦh���W������b�o�̳c��A�Ʊ�A�|
���w�C��W���ۤ@�ӵP�l(note)�C
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
	    "west" : __DIR__"room062",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	setup();
	replace_program(ROOM);
}