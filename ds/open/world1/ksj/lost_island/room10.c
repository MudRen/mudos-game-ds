#include <ansi.h>
inherit MOBROOM;

void create()
{
        set("short", "��@�q��"HIG"�~��"NOR);
        set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���W���R�ۤC�m�����M�_�������ΡA�����i�H�ݨ�
�øV���~�b��줤�b�]�V���A�񲴱�h���L�H�ϡA�k�M�O�ʪ����@�~
�緽�A�F��O���q�J�����s���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "west" : __DIR__"room11",
        "south" : __DIR__"room5",
        "north" : __DIR__"room15",
        ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("chance",25);
	set("mob_amount", 2);
        set("mob_max",1);
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/blade-mink",
        }) );
        setup();
}
