#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "迅掠龍" , ({"paleozoic dinosaur","dinosaur"}) );
  set("long",@LONG
恐龍大至分成三大族群：黑瑞龍亞目、龍盤目和鳥盤目，恐龍於一億八
千萬年前（侏羅紀）最為興盛，真正成為地球霸主，佔據了陸、海、空
三大生態領域，牠們稱霸地球約一億六千萬年之久，最後一批恐龍於六
千五百萬年前（白堊紀）滅絕。然而你卻不知道為何這隻迅掠龍，是怎
麼出現在這邊的。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age", 150 );
  set("gender", "雄性" );
  set("level", 25 + random(3) );
  set("limbs", ({ "頭部","胸部", "背部", "爪子", "尾巴", "大腿" }) );
  set("verbs", ({ "bite", "claw" }) );
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
	if(random(2) ) carry_object(__DIR__"obj/dinosaur-skin");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-bone");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-chine");
	if(random(5) == 1 ) carry_object(__DIR__"obj/dinosaur-eye");

}
