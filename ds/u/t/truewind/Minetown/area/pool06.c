#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�a�U���D");
        set("long", NOR""+
"���⤣�������A�º������a�U���D�A�o�O�q�ϩ~���M�q�u��H��\n"+
"�ͪ������t�ΩҦb���a��A�@���@�����޽u�����b�|�P��A�U���D��\n"+
"�����@�����D�A���G�O�~���D�n�������ӷ��C�o�̬O���D�����Y�A��\n"+
"�W���X�D���_���_���_�X���ӡC\n\n"+
"�@��"HIG"�����D(river)"NOR"�q�����y�L�h�C\n\n");
        set("current_light", 0);
        set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"pool05",
]));
        set("objects", ([ 
        __DIR__"npc/weasel.c" : 2,
        __DIR__"npc/weaselking.c" : 1,
]));

	setup();
}