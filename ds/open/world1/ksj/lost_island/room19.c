#include <ansi.h>
inherit MOBROOM;

void create()
{
        set("short", "��@�q��"HIG"�~��"NOR);
        set("long", @LONG
�o�̬O�@��L�ڪ��j���A�����ν����C�A����A�٦��\�h����
�W�����Ӫ��A���W���R�ۤC�m�����M�_�������ΡA�����i�H�ݨ�
�øV���~�b��줤�b�]�V���A�񲴱�h���L�H�ϡA�k�M�O�ʪ����@�~
�緽�A����O�@�B�s���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room18",
  "west" : __DIR__"room20",
  "south" : __DIR__"room14",
  "north" : __DIR__"room26",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("chance",15);
	set("mob_amount", 2);
        set("mob_max",1);
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/unicorn",
        }) );
        setup();
}