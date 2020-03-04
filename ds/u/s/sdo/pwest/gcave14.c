inherit ROOM;

void create()
{
	set("short", "地下河道旁");
	set("long", @LONG
你看著地下河流，才知道：『原來水聲是從這裡發出來的阿。』
緊鄰著你的腳邊，一陣陣湍急的河水快速的流過，濺起的水花偶爾還
會噴到你的腳上，讓你自然而然的離開一點。看著河水流向黑暗的另
一頭，讓你有一種神秘的感覺。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"gcave13",
	]));

	setup();
	replace_program(ROOM);
}
