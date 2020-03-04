inherit ROOM;
void create()
{
  set ("short", "古墓前空地");
  set ("long", @LONG
這裡黃沙滾滾，其壯闊景象有如江河之浪滔滔不絕，只見古道悠
悠，綿延不絕，在這座山裡竟有如此廣闊的空間，只見在一旁有個巨
大石碑，上頭寫著：

『此山得天獨厚，吾潛心修研，五十餘載飛如梭，天機秘要盡得真傳
，吾以得天歸，古墓暨陣法留之後人為記，當則善用，免千古遺憾。
　　　　　　　　　　　　　　　　　　　　－老頭兒於萬龍古墓』
LONG
);
  set("exits", ([
  "north" : __DIR__"room79",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
  replace_program(ROOM);
}
