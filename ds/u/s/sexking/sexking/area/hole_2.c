#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIR"test"NOR);
  set ("long", @LONG
�o�̴N�O�ǻ������ʦL���]�F�A�u���u�����i�̭̤~����
��D�ԫʦL���]������A���g�i�J�ʦL���]�D�Ԫ��H���d�ʤH�A
����F�̫ᬡ�ۥX�Ӫ��o�u�����ӤH�A�o����i�h���W�n�N�]
���û����o�즿��W���q�|�C
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
        "enter" : __DIR__"hole_2",
  ]));
        setup();
}
