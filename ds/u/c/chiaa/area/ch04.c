// Room: /u/c/chia/area/ch04
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "�ȪZ�j��");
  set ("long", @LONG
�A�@���n��,�u���s������,���T��o�̤j�P����,��Ӧ��B�����ȪZ��,�O�@�ؽ�a�۷��w������,�Ӧ��D���K�O�H�ȪZ���Ӻc����,����j��W�w�Ф��V,�Ѧ��i���~���復���R�@�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"ch09",
"north" : __DIR__"ch0",
]));

  setup();
  replace_program(ROOM);
}

