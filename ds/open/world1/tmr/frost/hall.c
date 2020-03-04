// Room: /open/world1/tmr/frost/hall.c

inherit ROOM;

void create()
{
	set("short", "�T����");
	set("long", @LONG
�T�����y�_���n�A���t�̤s�ӿv�A�������ѩ^�ѡB�a�B���T�x�j�Ҷ�
���C�T�����b�W�W�M���~ò���D�W�w�ˤ���A�ΥH�Ӧ����Y�B�J�Y�M�伵
�Xò�����q�A�Xò�V���A������h�Ƥ]�V�h�A�Φ��u���Ӧh�ܪ����u�A��
���ӨI�����j�γ��ܱo�z�h�嶮�A�Φ��F�@�ئ��P���B�R�P�ʡB��P�X��
�M�Ӭ��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"court3",
]));
	set("current_light", 1);
        set("objects", ([
                __DIR__"npc/mo-yue-ding":1,
        ]) );

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
