inherit __DIR__"waterroom";
void create()
{
set("short","遺跡─水");
set("long",@LONG
你現在已經差一些就成功通過測驗了，只要把最後的關卡
突破，便就可以離開艱辛的測驗了，但是最後的關卡可是不容
易的，開始準備好你的一切裝備迎接挑戰吧，現在只有鼓起勇
氣全力迎戰了。
LONG);
set("exits",([
"west":__DIR__"fowater_21", 
"northeast":__DIR__"fowater_20",
"southeast":__DIR__"fowater_25",
]));
setroom();
setup();
}             











