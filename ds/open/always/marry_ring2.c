#include <ansi.h>
#include <armor.h>
inherit FINGER;

string getage(object ob);
void query_each_other(object me);

void create()
{
  set_name(WHT"結婚戒指"NOR,({"marry ring","marry","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("basic_long",HIW"指令 - 給親愛的人的悄悄話: honey <文字>\n"NOR+WHT"這是一只純銀製的指環，上面還鑲了一顆小小的鑽石。\n上頭刻了一行小小的字：我的至愛 "NOR);
    set("value",0);
    set("material","diamond");
    set("no_drop",1);
    set("no_sell",1);
    set("no_sac",1);
    set("unit","只");
  }
  setup();
}

void init()
{
  object me = this_player();

  add_action("do_honey","honey");
  add_action("do_honey_nick","honey_nick");

/*  if(!me->query("marry_id"))
  {
    call_out("error_msg",2);
    return;
  }*/
  set("wear_msg",NOR+WHT"$N戴上$n"WHT"，對天大喊『親愛的 "HIC +me->query("marry_id")+ NOR+WHT" 請賜與我愛的力量！』。\n"NOR);
  set("unequip_msg","$N脫下一只$n。\n");

  remove_call_out("query_each_other");
  call_out("query_each_other", 0, me);
}

void query_each_other(object me)
{
        object ob;
        string str;

        if( !me ) return;
        if( !str=me->query("marry_id") )
        {
                call_out("error_msg", 2);
                return;
        }
        ob = new("/obj/unnamed.c");
        if( !ob->query_restore(str) )
        {
//              write("**DEBUG** ob uid:"+ getuid(ob) + " ob euid" + geteuid(ob) +"\n");
                write(HIR" (你的另一半已經消失了.. 戒指將自動銷毀。 )\n"NOR);
                message_vision(HIG"只見$N輕飄飄地，將結婚戒指給扔了...。\n"NOR, me);
                me->delete("marry_id");
                destruct(this_object());
                destruct(ob);
                return;
        }
        else if( ob->query("marry_id") != getuid(me) )
        {
//              printf("**DEBUG** object: %s level: %d marry_id: %s ob_uid: %s ob_euid: %s\n", file_name(ob), ob->query("level"), ob->query("marry_id"), getuid(ob), geteuid(ob));
                write(HIR" (似乎"+gender_self(me->query("gender"))+"的另一伴已變了心..。 )\n"NOR);
                message_vision(HIY"$N傷心地將$n給丟棄，丟棄在空氣中，消失不見了∼\n"NOR, me, this_object());
                destruct(this_object());
                destruct(ob);
                return;
        }
        else if( ob ) destruct(ob);
        return;
}

void error_msg()
{
  write(HIC"你的結婚戒指似乎出了一些問題，必需趕快回報巫師。\n"NOR);
  return;
}

int do_honey(string str)
{
  object ob, me = this_player();
  if(!me->query("marry_id")) return notify_fail("你的結婚戒指上並沒有刻著你配偶的名字！請趕快回報巫師！\n");
  if(!str) return notify_fail("你想對你的另一半說什麼?\n");
  ob = find_player(me->query("marry_id"));
  if(!ob || !environment(ob)) return notify_fail("你的配偶可能還沒上線，或是己經離線了，因此無法傳送訊息。\n");
  tell_object(ob,HIR +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  write(HIR"To " +getage(ob)+ ", "NOR+WHT +str+ "\n"NOR);
  return 1;
}

string getage(object ob)
{
  object me = this_player();

  /* --------- 暫時取消依年齡稱呼 ------------
  if(ob->query("gender") == "女性")
  {
    if(ob->query("age") < 30) return "寶貝";
    if(ob->query("age") < 50) return "老婆";
    if(ob->query("age") < 70) return "老伴";
    return "我說老太婆啊";
  }
  else
  {
    if(ob->query("age") < 30) return "親愛的";
    if(ob->query("age") < 50) return "老公";
    if(ob->query("age") < 70) return "老伴";
    return "我說老頭子啊";
  }
    -------------------------------------------------------- */
  if(me->query("marry_nick")) return me->query("marry_nick");
  return "親愛的";
}

int do_honey_nick(string str)
{
  if(!str) return notify_fail("你想稱呼你的另一半為什麼?\n");
  if( strlen(str) > 16 ) return notify_fail("名字取的太長了，請想一個短一點的.\n");
  this_player()->set("marry_nick",str);
  write("Ok.\n");
  return 1;
}

string long()
{
  if(this_player()->query("marry_id")) return query("basic_long") + HIC +this_player()->query("marry_id") +"\n"NOR;
  return query("basic_long") +HIY"這裡竟然什麼都沒刻?! 必需趕快回報巫師。\n"NOR;
}

int query_autoload() { return 1; }

