// This is a room made by roommaker.
inherit ROOM;
void create()
{
 set("short", "斜坡");
 set("long",@LONG
這裡是一條海底斜坡，許多小魚在海底游來游去。越往下走就越暗，如果
身上沒有充足的照明工具還是不要下去的好。旁邊的岩石看起來十分的鬆軟，  
似乎隨時都有倒塌下來的可能。

LONG
);
set("Env_sector_type","Under_water");
 set("exits", ([ 
  "westup" : __DIR__"sea5",
  "eastdown" : __DIR__"sea18",
  ]));
 set("no_clean_up", 0);
 set("outdoors",1);
 setup();
 replace_program(ROOM);
}
