inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你深深吸了一口氣，感覺的附近傳了肅穆氣息，看來最後
的考驗就要來臨了，連此地都能感應到的強大氣息，可見最後
的關卡所在之人該不是泛泛之輩，但是你也沒有退路，現在只
能努力往前繼續邁進了。
LONG);
set("exits",([
"north":__DIR__"fowater_19", 
"southeast":__DIR__"fowater_23",
"southwest":__DIR__"fowater_22",
]));
setroom();
setup();
}             











