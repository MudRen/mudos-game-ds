#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIW"�B�]"NOR);
        set("long", HIW @LONG
�o�̬O�@�ӥ��j���B�]�A�P�򳣬O�p�p���B�h�ϱo���B�R���ۭ�
�����H��A�B�h�����ӥi�H�ݨ�Q�ᵲ���ʪ��A�Ĥƪ����w�b�a�O�W
�Φ��@�����M�����p���y�C
LONG NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room20",
]));
        set("no_clean_up", 0);
        set("no_auc", 1);
        set("objects",([
        __DIR__"ice.c":1,
        ]));
        set("light", 0);
        setup();
}
