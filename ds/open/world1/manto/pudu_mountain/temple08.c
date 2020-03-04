inherit ROOM;

void create()
{
        set("short", "松林");
        set("long", @LONG
冷冽的寒風盡數被北端的天岩所拒，此處松林竟是風平氣和。微風拂
動，青松搖晃，卻也聽不到松濤之聲。松林中本就沒有路，尋隙而行，其
間兔、貂、白鹿悠然自得，不慌不忙，甚至還有白鶴在林間輕舞，姿態嫻
雅，舒展自如，卻是看也不看你一眼。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"temple10",
  "north" : __DIR__"temple09",
  "south" : __DIR__"temple05",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
}
