// Room: /ruzhou/xifu-tang.c //舉辦婚宴所在
// llm 99/07/09

inherit ROOM;
void create()
{
	set("short", "喜福堂");
	set("long", @LONG
這里是迎賓樓的二樓，寬敞地可以擺下三十多張八仙桌，正中挂
著大大的紅色喜字，由于常常有人在此舉辦婚宴，這里的紅燭也就長
明，地上鋪著厚厚的大紅地毯，一派喜氣洋洋的景象。你站在樓上眺
望，可看見碧波湖水，崇山峻嶺。
LONG
);
	set("exits", ([
                "down" : __DIR__"yingbin-lou1",
	]));

	setup();
   replace_program(ROOM);
}
