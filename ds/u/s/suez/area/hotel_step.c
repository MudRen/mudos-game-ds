// Room: /u/s/suez/area/step1.c
inherit ROOM;
void create()
{
	set("short", "樓梯");
	set("long",@LONG 
陣陣蟬聲由外面的小窗傳入，柔和的一襲光線落在你的腳邊，讓你幾
乎捨不得向上走去。如果是在晴朗的夜晚，淡藍的月光就這樣充斥著這一
小塊空間，讓人覺得很浪漫。聽說客棧老闆娘偶而會來這裡，就這樣看著
窗外的月光，輕輕哼著不知名的小曲，放開一頭烏絲隨晚風飛揚。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "westdown" : __DIR__"hotel_path",
            "westup" : __DIR__"hotel_two",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}