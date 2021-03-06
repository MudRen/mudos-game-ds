// Room: /open/world1/tmr/area/mouse_hole.c

inherit ROOM;

void create()
{
	set("short", "鼠洞");
	set("long", @LONG
你正在一個洞裡，似乎是老鼠打出來的洞，可是洞中空間寬廣，就算
再多來幾個人也不會覺得擁擠。你發現四周都貼滿喜氣洋洋的吉祥話，氣
氛十分熱鬧溫馨，相當有過年的感覺。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"inn_3f",
]));

         set("objects", ([ /* sizeof() == 1 */
                  "/open/world1/tmr/game/2008_year/npc/simon" : 1,
//                 "/open/world1/tmr/game/2008_year/npc/alvin" : 1,
                "/open/world1/tmr/game/2008_year/npc/theodore" : 1,
                "/u/t/tmr/game/2008_year/board" : 1,
          ]));
	setup();
	replace_program(ROOM);
}
