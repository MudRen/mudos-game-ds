#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIY"太陽之歌"NOR,({"sun-song ankle","ankle"}));
  set("long", @LONG  
太陽之歌是一個感人的故事，故事講述住在海邊城市的雨音薰患上著色性乾皮症
（Xeroderma Pigmentosum，簡稱XP），身體不能照射陽光。因此她的生活與正常
人相反：月出時她的活動時間開始；陽光出來時就睡覺。即使這樣，她有支持她
的家人、好朋友，每日快樂地生活。此外音樂對她來說是比甚麼都重要的東西。
在歌唱中，好感受到生存的意義。直到遇上一位少年，她的命運出現了很大的改變。
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("material","gold");
  }

    set("not_clone",1);
  set("armor_prop/int",3 );
  set("armor_prop/str",3  );
  set("armor_prop/dex",3  );
  set("armor_prop/con",3  );
  set("armor_prop/armor", 5 );
  set("armor_prop/shield", 5 );
  set("armor_prop/show_damage", 1);
  setup();
}

