#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIW"�d�j�۪L"NOR);
        set("long", @LONG
�o�̬O�a��s���a�ո����������A�o�Ӧa��������m�A�a�W�u��
�@�ǹs�P���۶��A�b�s�������@�B�s�}�A���ɦ��j�l�������q�}���j
�X�A�o�X�I�����㪺�n���C
LONG);
        set("exits", ([
            "east" : __DIR__"room41",
            "enter" : __DIR__"room45",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("no_auc", 1);
        setup();
}
