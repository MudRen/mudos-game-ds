#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", "舊磐龍遺址");
  set ("long", 
"來到一大片岩壁之前，岩壁上書朱漆『"HIR"磐龍城"NOR"』二字，為何人所書，\n"
"已不可考，字跡古拙雄奇。在岩壁之旁，尚另有石碑，上頭寫的密密\n"
"麻麻的草書，難以看清。\n"NOR
);

  set("exits", ([
  "east" : __DIR__"room40",
  "west" : __DIR__"room42",
  "north" : __DIR__"room43",
]));
  set("item_desc", ([
  "石碑" : "一朝在曦，十年枯\榮乾坤，未見百重山。\n千古流傳，萬代道法妙門，坐觀虛無界。\n\n--天機子--\n",
]));
  set("outdoors", "land");
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
