#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HBK "暗黑"HIR"母牛之王" NOR,({"dark cow-king","cow", "king"}) );
  set("long","這是一隻像人一樣用兩隻腳走路的母牛，漫無目地到處走著，看起來非常的詭異。\n");
  set("race", "beast");
  set("unit","頭");
  set("title",HBK "幽暗牯牛草原" NOR);
  set("age", 80);
  set("level", 70);
  set("limbs", ({ "頭部", "腹部","胸部","背部", "腳", "牛角", "乳頭", "生殖器", "牛眼"}) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
        (: random_move :),
        }) );
  set("chat_combat_chance",30);
  set("chat_combat_msg", ({
        (: random_move :),
        }) );
      set("max_hp", 1200000 + random(5) * 100000);
  setup();
  

  carry_object(__DIR__"obj/meat");
  carry_object(__DIR__"obj/meat");
  carry_object(__DIR__"obj/meat");
  carry_object(__DIR__"obj/meat");
  carry_object(__DIR__"obj/meat");
}

void heart_beat()
{
        if( query("hp") < 1 ) {
        this_player()->remove_all_killer();
        die();
        return;
        }
        // 戰鬥中不會攻擊
        add_block(2);
}



int filter(object inv)
{
        if( inv->query_autoload() ) // save eq
                return 0;
        if( inv->query_unique() )  // daily eq
                return 0;
         if( inv->id("undead_item") )  // doll item
                  return 0;
       if( inv->id("horse") )  // horse npc
                  return 0;
       if( inv->id("quest_ob") )  // notebook
               return 0;
       if( inv->id("mail_ob") )  // mail object
               return 0;
       if( inv->id("horse") )  // horse npc
                 return 0;
       if( inv->query("not_clone") )  // not cloneable
                 return 0;
        return 1;
}


void cloneEquip(object me) {
        object *inv;
        object item;
        string msg;
        inv = all_inventory(me);
        if( !sizeof(inv) ) return;
        inv = filter_array(inv, (:filter:) );
        // 過瀘後的物件數量至少要有8件
        if( sizeof(inv) < 8 ) return;
        
        // 獲得 item
item = new( base_name(inv[random(sizeof(inv))]) );
if( !objectp(item) ) return;

        msg = sprintf(HBK+"【牯牛草原】"NOR"%s(%s)出土了。[%s]\n"NOR,item->query("name"), item->query("id") ,ctime(time()));
        message("system", msg ,users());
        msg = sprintf(HIB "【系統】Clone: %s -> %s"HIB"(%s)\n"NOR, me->query("id"), item->query("name"), item->query("id") ,ctime(time()));
        message("channel:sys", msg ,users());
item->move(this_object());
}

void getReward(object me) {
        string *items = ({
                "10_bar.c","10_bio.c","10_wit.c","10_sou.c","10_tec.c"
        });

    // 60% 機率獲得 10% merits 卷軸
    if( random(100) < 60 )
        new("/open/enhance/" + items[random(5)])->move(this_object());
    
    // 30 % 機率從玩家身上複製一件 item
   if( random(100) < 30 )
        cloneEquip(me);
    
    // 賺到1點戰藝
   me->add("war_art", 3);
   tell_object(me, HIW "你得到 3 點戰爭藝術。\n"NOR);
}
        
void die()
{
        object ob;
   if( !ob = query_temp("last_damage_from") )
           ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }
        
    getReward(ob);

   ::die();
   return;
}

