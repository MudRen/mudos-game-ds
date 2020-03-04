inherit ROOM;
void create()
{
    set("short", "皴玉古城北門");
        set("long", @LONG
    一堆青石亂苔駁雜的散亂各處，兩旁長滿藤蔓草樹的山壁中夾了個石
頭城門。城門前也長滿了高大的喬木，像道拱門般圍繞著入口的小徑，晴
朗的日子裡，陽光透過枝葉在石板路上輕輕晃動，清涼的微風吹拂著過往
行人。在這似乎被冬天遺忘似的綠色城門前，你只覺得心曠神怡，但是城
門旁的石碑卻也記載了殘酷的歷史以及血腥的過去，望著城門上幾已消蝕
脫落的「皴玉」兩字，你不禁痴了。

LONG
);
	set("exits",([
	"south" : __DIR__"map_3_6",
	"north" : __DIR__"map_1_6",
	]));
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

