inherit ROOM;

void create()
{
	set("short", "疾風門之房");
	set("long", @LONG
這裡是疾風門門主的房間，在這裡有許許多多的刀槍劍斧，也有許
多的盆景，住這兒的人看來還頗懂詩情畫意，疾風門的門主目前因為有
事而外出，所以這個房間平常就很少人出入，不過在擺劍架旁的書架卻
如似新品，好像沒有半丁點灰塵，書架上也有些尋常人家所有的易經、
三字經，腳下的地毯也幾乎起了毛，上面是繡著一隻雄壯威武的神龍，
象徵著疾風門興盛的樣子。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"flurry48.c",
]));
	set("objects", ([
                "/open/world1/alickyuen/wind/ling" : 1,
"/open/world1/cominging/area/sorsin_man":1, // add by js
	]));
	set("light",1);
	setup();
}
void reset()
{
	:: reset();
//        call_out( (: find_living("wind_big_guy")->help():), 120);
}
