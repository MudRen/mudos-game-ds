inherit NPC;
void create()
{
set_name("老蚌", ({ "old clam","clam" }) );
set("age",99);
set("level",61);
set("long", @LONG
一個老蚌, 從牠殼上的苔蘚看來, 應該上百歲了吧..
LONG
);
set("race","野獸");
//set("coin",260+random(130));
//set("chat_chance", 8);
//set("chat_msg", ({
//"．．\n",
//}));
set("limbs", ({ "頭部", "身體", "外殼", "腹部"})); //受攻部位
set("verbs", ({ "bite","crash" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
add_temp("apply/armor",400);
carry_object(__DIR__"item/pearl");
}

void init()
{
 add_action("no_cast","c");
}

int no_cast(string arg)
{
 if(arg && random(10) > 5 )
 {
  message_vision("$N突然噴出一堆銀色的粉末, $n覺得一陣頭暈..只好放棄施法.\n",this_object(),this_player());	
  this_player()->start_busy(2);
  return 1;
 }	
 return 0;
}
