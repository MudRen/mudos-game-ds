#include <ansi.h>
inherit MOBROOM;
void create()
{
  set ("short", HIG"�˶�"NOR);
  set ("long", @LONG
�o�̺ص۳\�h�C�ˡA�a�A�l�ޡA��M�O���H�S�N�[�H�Ӯƪ��A��
�l���G���K���P�A�L���j�ӡA�˸��F�F�@�T�A�Ϧp�@�~�緽�C
LONG
);

  set("exits", ([
  "west" : __DIR__"room6",
]));
        set("chance",75); // ���H��robot ,100->75
        set("mob_amount",5);
        set("mob_object",({
  __DIR__"npc/npc5",
  __DIR__"npc/npc6",
}) );
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
}

