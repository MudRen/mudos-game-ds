inherit BANK;

void create()
{
        set("short", "歲寒錢莊");
        set("long", @LONG
這是本地最大的錢莊，直屬於「傲梅山莊」的產業，是最穩靠的錢莊
，此縣的人有九成都是寄存在此，你可以看看左面牆壁上的木匾，以了解
這家錢莊提供了什麼服務。
LONG
        );
	set("objects",([	
		__DIR__"npc/guard" : 2,
		__DIR__"npc/banker" : 1,
	])	);
        set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"street4",
        ]));
  	set("no_kill",1); //保持能存錢.
	 set("item_desc", ([
        "木匾" : @LONG
   歲寒錢莊提供的服務有:

deposit      : 存錢
withdraw     : 提錢	

LONG
        ]) );

	set("light",1);
        set("no_clean_up", 0);

        setup();

}

