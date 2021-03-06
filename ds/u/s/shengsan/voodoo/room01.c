inherit ROOM;

void create()
{
	set("short", "翠林石階");
	set("long", @LONG
在你的身旁都是青翠的竹林，隨著風吹林中的竹葉不時地發出沙沙的
聲音。你腳下的石階是用普通的石頭砌成的，並沒有什麼怪異之處。無意
間你發現在石階旁有一個牌子(sign)。
LONG
	);

	set("item_desc", (["sign":@NOTE
[1;32m
		巫毒教禁地,非請勿入。
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 2 */
            "up" : __DIR__"room02",
	    "out": __DIR__"room00",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/believer" : 1,
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
