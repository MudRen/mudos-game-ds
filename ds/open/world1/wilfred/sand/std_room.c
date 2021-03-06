// 這是要作成繼承檔, 給伏羲石陣之用  wilfred@DS

#include <ansi.h>
#include <room.h>
inherit ROOM;

string find_item();

void setup()
{
  ::setup();
  set ("short","未定義");
  set ("long","未定義");
  set("no_clean_up", 0);
  set("no_recall",1);
  set("index",0);
}

void change(int index)
{
// 原本用 mapping 的結果為何都指定不到原資料的排法, 只好改用兩個 string 陣列來作

  string *str1 = ({
"未定義",HIW"乾門"NOR,HIC"巽門"NOR,NOR""WHT"坎門"NOR,HIY"艮門"NOR,
HIW""BLK"坤門"NOR,HIB"震門"NOR,HIR"離門"NOR,HIG"兌門"NOR
});

  string *str2 = ({
"\n未定義\n\n",
"\n這是一個相當明亮的地方，白色的光線柔和不刺眼。\n\n",
"\n一陣陣涼風吹過來，令人精神振奮，看來這裡是休息的好地方。\n\n",
"\n這裡是一片湖，湖水是銀色的，令人納悶。\n\n",
"\n放眼四週盡是土黃色的岩石，看來沒什麼危險。\n\n",
"\n迎面而來的是陰冷的黑氣，幾乎伸手不見無指。\n\n",
"\n這裡雷聲隆隆，偶爾還有小型電球四處流竄著。\n\n",
"\n這裡四處都燃燒著奇異的火焰，其高熱令人心神不寧。\n\n",
"\n此處盡是泥沼，不時還有綠色的氣體噴出，令人作嘔。\n\n"
});

  set("index",index);

  set("short",str1[query("index")]);
  set("long",str2[query("index")]);
}

void init()
{
  object me = this_player();
  int index = random(10)+1;
  int i, damage;

  delete("item_desc");
  me->start_busy(1);
  if(!living(me)) return;
  switch(query("index"))
  {
    case 1 : if(!random(5))
             message_vision(HIW"在不遠處的角落突然閃了一下，匆匆一瞥間，似乎看到一個銀色物品？\n"NOR,me);
             set("item_desc",([ "銀色物品" : (: find_item :) ]));
             break;
    case 3 : message_vision(NOR""WHT"湖水突然暴漲起來！$N一個不小心，被沖倒在地，好半天爬不起來！\n"NOR,me);
             me->start_busy(7);
             break;
    case 6 : message_vision(HIB"哇靠！有"+chinese_number(index)+"顆電球朝著$N衝了過來，$N這麼有吸引力？！\n\n"NOR,me);
             for(i=0;i<index;i++)
             {
               damage = random(20)+1;
               message_vision(HIB"$N慘遭電球擊中，被電得哇哇大叫！ ("+damage+")\n"NOR,me);
               me->add("hp",-damage);
             }
             call_out("tender",10,me);
             break;
    default : break;
  }
}

int room_effect(object me)
{
  if(!living(me)) return 1;
  switch(query("index"))
  {
    case 2 : if(!random(4))
             message_vision(HIC"一陣涼風吹來，吹在$N的臉上，$N覺得精神好了許\多。\n"NOR,me);
             if(me->query("maxhp") > me->query("hp")) me->add("hp",20);
             break;
    case 7 : message_vision(HIR"$N抵擋不住高熱，被燒得皮開肉綻！\n"NOR,me);
             me->add("hp",-30);
             me->apply_condition("blooding", me->query_condition("blooging")+5);
             break;
    case 8 : message_vision(HIG"$N不小心吸入了一點綠色氣體，登時頭昏眼花！\n"NOR,me);
             me->add("hp",-30);
             me->apply_condition("poison", me->query_condition("poison")+5);
             break;
    default : break;
  }
  return 1;
}

string find_item()
{
  object me = this_player();
  if(random(3) || me->query_temp("find_item"))
  {
    message_vision(HIW"$N仔細望去，發現原來只是塊石頭。\n"NOR,me);
    this_object()->delete("item_desc");
    return "";
  }
  message_vision(HIW"\n$N發現一個銀色的箱子！！\n\n"NOR,me);
  new(__DIR__"npc/obj/obj22")->move(this_object());
  this_object()->delete("item_desc");
  me->set_temp("find_item",1);
  return "";
}

void tender(object me)
{
  if(!me) return;
  if(me->query("class1") == "凌雲寺")
    message_vision(HIW"\n『轟！！』$N突然又被一陣急雷打中，$N的光頭突然亮了起來！\n\n"NOR,me);
  else
    message_vision(HIB"\n『轟！！』$N突然又被一陣急雷打中，被電得全身發麻！\n\n"NOR,me);
  me->add("hp",-100);
  return;
}
