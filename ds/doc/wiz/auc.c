// auc.c
// Write by Wilfred@DS   2000/10/29
// Rewrite by wilfred@DS 2000/12/1
// 有時間再作最佳化

#include <ansi.h>
#include <room.h>

#define AU_ROOM "/obj/void"
#define AUCMAN "芭樂拍賣員(Aucman)"

inherit F_DBASE;

object item, owner, owner2;
object *inv, *goods;
string str1, str2;
int au1, au2, au3, amount, i, j;

// 物品資料 -----------------
int item_space, item_durable;
string item_name;
// --------------------------

string space(int index);
string space_e(int index);
void auc_what(object who);
void reset_auc();
void tune_auc(object me);

void create()
{
  seteuid(getuid());
  set("no_clean_up",1);
  set("name","芭樂拍賣員");
  set("id", "aucman");
}

int main(object who ,string arg)
{
  int amount_temp;

  tune_auc(who);
  if(!arg) return notify_fail("不知道拍賣格式請輸入 help auc\n");
  if( arg == "what" )
  {
    auc_what(who);
    return 1;
  }
  if( arg == "auto" )
  {
    au2 = au3 * 110 / 100;

    if( str2 == "over" ) return notify_fail("現在並沒有拍賣任何物品。\n");
    if( who == owner || who == owner2) return notify_fail("你不能再出價了。\n");
    if(!environment(item)) return notify_fail("拍賣中的物品出了一些問題，請稍後。\n");
    if( who->query("bank/"+space_e(item_space)) < au2 ) return notify_fail("你沒那麼多存款。\n");
    if( who->money_type() != item_space ) return notify_fail("你所處的時空與拍賣中的物品不同無法叫價。\n");

    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
    "[" +space(item_space)+ "] 有人出價 "HIY +au2+ HIG" 元買" +item_name+ HIG"[狀況→" +item_durable+ "%]，有沒有人要加價？\n"NOR, users() );

    remove_call_out("no_man1");
    remove_call_out("no_man2");
    remove_call_out("no_man3");
    remove_call_out("have_man");

    call_out("no_man1",10);

    owner2 = who;
    au3 = au2;
    return 1;
  }

  if( !str2 ) str2 = "over";
  if( sscanf(arg,"%s for %d", str1, au1) == 2)
  {
    if( str2 != "over" ) return notify_fail("請先等這場拍賣會結束。\n");

    reset_auc();
    sscanf(str1,"%d %s", amount, str1);
    if(!objectp(item = present(str1, who)) ) return notify_fail("你沒有這件物品。\n");
    if(item->query_temp("invis")) return notify_fail("你沒有這件物品。\n");
    if( item->query("equipped") ) return notify_fail("你正裝備著這樣東西。\n");
    if( item->query("secured") ) return notify_fail("請除保存狀態。\n");

    if( !this_player()->money_type() ) return notify_fail("你所處的時空無法進行拍賣。\n");
    if( item->query("money_id")   ||
        item->query("value") < 10 ||
        item->query("no_auc")     ||
        item->query("no_drop")    ||
        item->query("no_give")    ||
        item->query("no_sell")    ||
        item->is_character()
      )
    return notify_fail("這東西不能拍賣！\n");

    if( amount )
    {
      if( amount > 50 ) return notify_fail("一次拍賣的數量不能超過 50 個。\n");
      inv = all_inventory(who);
      for(i=0;i<sizeof(inv);i++)
      {
        if(base_name(inv[i]) != base_name(item)) continue;
        j++;
      }
      if(j < amount) return notify_fail("你沒有這麼多的東西。\n");

      j = 0;
      for(i=0;i<sizeof(inv);i++)
      {
        if(base_name(inv[i]) != base_name(item)) continue;
        if(j >= amount) continue;
        goods[j] = inv[i];
        j++;
        inv[i]->move(AU_ROOM);
      }

      item_name = chinese_number(amount)+
                  item->query("unit")+item->query("name")+
                  "(" +item->query("id")+ ")"NOR;
    }
    else
    {
      item_name = item->query("name")+"("+item->query("id")+")"+NOR;
      item->move(AU_ROOM);
    }

    if(au1 < (item->query("value") * 70 / 100) )
    {
      tell_object(who, "您輸入的金額有誤，系統自動設為物品原價的 70%。\n");
      au1 = item->query("value") * 70 / 100;
    }
    if(au1 > 100000 )
    {
      tell_object(who, "您輸入的金額超過限制，系統自動設為上限 100000 元。\n");
      au1 = 100000;
    }
    item_space = who->money_type();
    item_durable = item->query_durable();

    message_vision("\n\t一位身穿制服的拍賣員，突然衝過來將$N的" +item_name+ "搶走了！\n\n",who);

    CHANNEL_D->do_channel( this_object(), "bala", HIG+AUCMAN+"﹕"+
    "[" +space(item_space)+ "] 有人拍賣" +item_name+ HIG"[狀況→" +item_durable+ "%] 底價 "HIC +(string)au1+ HIG" 元，有沒有人要加價？\n"NOR, users() );

    owner = who;
    owner2 = owner;
    au3 = au1;
    str2 = "yes";

    call_out("no_man1",10);

    return 1;
  }
  else
  {
    if( sscanf(arg,"%d %s", str1, au2) == 2 || sscanf(arg,"%d", au2) != 1) return notify_fail("不知道拍賣格式請輸入 help auc\n");
    if( str2 == "over" ) return notify_fail("現在並沒有拍賣任何物品。\n");
    if( who == owner || who == owner2) return notify_fail("你不能再出價了。\n");
    if(!environment(item)) return notify_fail("拍賣中的物品出了一些問題，請稍後。\n");
    if( who->query("bank/"+space_e(item_space)) < au2 ) return notify_fail("你沒那麼多存款。\n");
    if(au2 < (au3 * 110 / 100) ) return notify_fail("每次叫價必須比前一次多 10% 單位的貨幣。\n");
    if( who->money_type() != item_space ) return notify_fail("你所處的時空與拍賣中的物品不同無法叫價。\n");

    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
    "[" +space(item_space)+ "] 有人出價 "HIY +au2+ HIG" 元買" +item_name+ HIG"[狀況→" +item_durable+ "%]，有沒有人要加價？\n"NOR, users() );

    remove_call_out("no_man1");
    remove_call_out("no_man2");
    remove_call_out("no_man3");
    remove_call_out("have_man");

    call_out("no_man1",10);

    owner2 = who;
    au3 = au2;
    return 1;
  }
}

int no_man1()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
  "[" +space(item_space)+ "] " +item_name+ HIG"[狀況→" +item_durable+ "%] 叫價 "HIC +au3+ HIG" 元第一次。\n"NOR, users() );

  call_out("no_man2",15);
  return 1;
}

int no_man2()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
  "[" +space(item_space)+ "] " +item_name+ HIG"[狀況→" +item_durable+ "%] 叫價 "HIC +au3+ HIG" 元第二次。\n"NOR, users() );

  if(owner == owner2)
    call_out("no_man3",10);
  else
    call_out("have_man",10);
  return 1;
}

int no_man3()
{
  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
  "[" +space(item_space)+ "] " +item_name+ HIG"才賣 "HIC +au3+ HIG" 元也沒人要，唉~~~~\n"NOR, users() );

  str2 = "over";

  if(!owner || !environment(owner) || owner->money_type() != item_space)
  {
    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
    "[" +space(item_space)+ "] " +item_name+ HIG"的原物主出了點問題，此物充公，嘻嘻。\n"NOR, users() );
    if( amount )
    {
      for(i=0;i<amount;i++)
        destruct(goods[i]);
    }
    else destruct(item);
    return 1;
  }
  else
  {
    tell_object(owner, HIW"拍賣員對你說道：『對不起！沒人要買ㄟ！』"NOR);
    if(environment(item))
    {
      tell_object(owner, item_name+ HIW"突然掉在你面前。\n"NOR);
      if( amount )
      {
        for(i=0;i<amount;i++)
          goods[i]->move(environment(owner));
      }
      else item->move(environment(owner));
    }
    else tell_object(owner, HIW"可是您的" +item_name+ HIW"也不見了，真抱歉，請您去問問巫師吧。\n"NOR);
    owner->save();
    return 1;
  }
}

int have_man()
{
  str2 = "over";
  if(!owner2                                           ||
     !environment(owner2)                              ||
     owner2->is_ghost()                                ||
     !item                                             ||
     !environment(item)                                ||
     owner2->money_type() != item_space                ||
     owner2->query("bank/" +space_e(item_space)) < au3
    )
  {
    CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
    "[" +space(item_space)+ "] " +item_name+ HIG"的拍賣會出了一點問題，因此取消此次的拍賣會。\n"NOR, users() );

    if(!owner || !environment(owner) || owner->money_type() != item_space)
    {
      CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
      "[" +space(item_space)+ "] " +item_name+ HIG"的原物主出了點問題，此物充公，嘻嘻。\n"NOR, users() );
      if( amount )
      {
        for(i=0;i<amount;i++)
          destruct(goods[i]);
      }
      else destruct(item);
      return 1;
    }
    else
    {
      tell_object(owner, HIW"拍賣員對你說道：『對不起！買方跑標了ㄟ，害我白跑一趟！』"NOR);
      if(environment(item))
      {
        tell_object(owner, item_name+ HIW"突然掉在你面前。\n"NOR);
        if( amount )
        {
          for(i=0;i<amount;i++)
            goods[i]->move(environment(owner));
        }
        else item->move(environment(owner));
      }
      else tell_object(owner, HIW"可是您的" +item_name+ HIW"也不見了，真抱歉，請您去問問巫師吧。\n"NOR);
      owner->save();
      return 1;
    }
    return 1;
  }

  CHANNEL_D->do_channel( this_object(), "bala",HIG+AUCMAN+"﹕"+
  "[" +space(item_space)+ "]" +item_name+ HIG"以 "HIC +au3+ HIG" 元賣出，謝謝惠顧。\n"NOR, users() );

  tell_object(owner2, HIC"\n\t拍賣員突然出現在你面前，將" +item_name+ HIC"丟在地上，隨即便走了。\n\n"NOR);
  tell_object(owner2, NOR+WHT"系統己自動從你的銀行存款中扣掉 " +au3+ " "+space(item_space)+"錢幣。\n"NOR);
  if( amount )
  {
    for(i=0;i<amount;i++)
      goods[i]->move(environment(owner2));
  }
  else item->move(environment(owner2));

  owner2->add("bank/" +space_e(item_space), -au3);
  owner2->save();

  if(!owner || !environment(owner)) return 1;

  tell_object(owner,HIY "\n扣除５﹪的手續費，你得到 " +(au3*95/100)+ " " +space(item_space)+ "錢幣，己存進您的銀行裡。\n\n" NOR);
  owner->add("bank/" +space_e(item_space), (au3 * 95 / 100));
  owner->save();
  return 1;
}

string space(int index)
{
  switch(index)
  {
    case 1 : return "古代";
    case 2 : return "現代";
    case 3 : return "未來";
    default : return "夢幻";
  }
}

string space_e(int index)
{
  switch(index)
  {
    case 1 : return "past";
    case 2 : return "now";
    case 3 : return "future";
    default : return "dream";
  }
}

void auc_what(object who)
{
  string msg = "";
  if( str2 == "over" )
  {
    tell_object(who, "現在並沒有拍賣任何物品。\n");
    return;
  }

  msg += "  目前喊價   " + au3+ "\n";
  msg += "  原價／單價 " + item->query("value")+ "\n";
  msg += "  狀況       " + item->query_durable()+ "%\n";
  msg += "  拍賣時空   " + space(item_space)+ "\n";
  msg += "  物品名     " + item->query("name")+ "(" +item->query("id")+ ")\n";

  if(item->query("skill_type"))
  msg += "  攻擊力     " + "＋ " +item->query("weapon_prop/damage")+ "\n";

  if(item->query("armor_type"))
  msg += "  防禦力     " + "＋ " +item->query("armor_prop/armor")+ "\n";

  if(item->query_autoload())
  msg += "  附註        [這件裝備是可以 SAVE 的]\n";

  msg += "物品簡介：   " + "\n" + item->query("long")+ "\n";

  tell_object(who, NOR+WHT"以下是拍賣中物品的詳細資料：\n－－－－－－－－－－－－－－－－－－－\n"NOR +msg+ NOR);
}

void reset_auc()
{
  amount = 0;
  goods = allocate(50);
  j = 0;
}

int help(object me)
{
  write(@HELP

  AUC 指令 (另見：help channels)

   指令格式： 1､拍賣物品時               <auc 東西 for 價錢>  
                                          <auc 數量 東西 for 價錢>
              2､叫價時                   <auc 價錢>
              3､查詢拍賣中物品的詳細資料 <auc what>
              4､自動叫價                 <auc auto>

   ●拍賣之起價在 物品原價70% ~ 100000 之間，請注意。●

HELP
);
  return 1;
}

void tune_auc(object me)
{
  string arg = "bala";
  string *tuned_ch = me->query("channels");

  if( pointerp(tuned_ch) && member_array(arg, tuned_ch) != -1 ) return;

  tuned_ch += ({ arg });
  me->set("channels", tuned_ch);
  me->save();
}
