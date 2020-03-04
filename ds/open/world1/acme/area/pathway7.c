// Room: /u/a/acme/old_area/pathway7.c
inherit MOBROOM;
void create()
{
	set("short", "小徑");
	set("long", @LONG
你只覺得這裡陰森森的，渾身不舒服，隱約可以聽見有狗在吠叫，
眼前突然一群黑色蝙蝠往你頭上飛去，往南邊你可以看到有一間略為殘
破的屋子。
LONG
	);
	set("no_clean_up", 0);
        set("chance",70);
        set("mob_amount",3);    //則最多出現三個怪物.
        set("mob_object",({     //設定怪物檔名.
            __DIR__"npc/bat",
        }) );
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"h1",
  "west" : __DIR__"pathway5",
]));
	setup();
}
