
inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIM"布娃娃"NOR, ({ "bu wawa", "wawa" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一隻可愛逼真的小布娃娃,你可以跟他玩耍(nie shua)。\n");
    set("unit", "隻");
    set("value", 100000);
  }
  setup();
}

int init ()  
{   
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
  return 1;
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
  return 0;

  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
  return 0;

  this_object()->set("name",arg);
  this_object()->set("long","一"+this_object()->query("unit")+arg+"。\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
  return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","一"+arg+this_object()->query("name")+"。\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_nie(string arg)
{
  string *dos = ({
    "用手指輕輕一捏",
    "輕輕捏了一下",
    "小心地捏一捏",
    "捏一捏",
    "輕碰了一下",
    "碰碰",
    "用手指點一點",
  });

  string *parts = ({
    "腦袋",
    "頭發",
    "臉蛋",
    "胖腮幫",
    "嘴嘴",
    "小嘴唇",
    "耳朵",
    "眉心",
    "長睫毛",
    "鼻子",
    "小鼻尖",
    "下巴",
    "小脖子",
    "手",
    "胳膊",
    "腿",
    "腳",
    "肚肚",
    "小屁屁",
  });

  string *actions = ({
    "張開小口吱吱地叫了兩聲。",
    "張開嘴啊喲了一聲。",
    "天真地呀呀叫出了聲音。",
    "睜開大眼睛吧嗒吧嗒地眨了幾下。",
    "睡意朦朧地慢慢睜開一對大眼睛。",
    "睜開眼睛，又滿意地合上眼睛睡著了。",
    "搖了搖碩大的腦袋。",
    "東倒西歪地努力抬起大腦袋。",
    "認真地點點腦袋。",
    "瞪著大眼睛看著$N。",
    "呆呆地看著$N，吃吃地笑出聲來。",
    "把胖胖的手指放到嘴裡，一邊吮吸一邊看著$N。",
    "把腦袋往兩邊一轉看了看，又抬頭看看$N。",
    "害羞地把腦袋往$N懷裡一鑽。",
    "甜甜地把大腦袋貼在$N身上。",
    "皺了一皺月兒眉。",
    "小老頭兒般地皺了一皺額頭。",
    "高興地把眼睛瞇成一條縫。",
    "咧開小嘴哇地一聲哭了出來。",
    "擺\出一副可愛的小苦瓜臉。",
    "張開小嘴哭得喘不過氣來。",
    "瞇著眼睛，張開小嘴笑了出來。",
    "甜蜜一笑。",
    "笑呀笑呀笑呀。",
    "呀呀喲喲地唱了幾句。",
    "高興地唱了起來：咿嚕啊哈哩……",
    "唱起搖籃曲：睡睡吧，乖乖耶……",
    "不高興地噘了噘小嘴。",
    "滿臉不高興嘟囔著小嘴兒。",
    "噘起小嘴兒眼兒一翻扭過頭去不理人了。",
    "用小手揪住$N的袖口。",
    "一把揪住$N的衣服死死不放。",
    "揪住$N的手眼巴巴地望著$N。",
    "伸出兩條小腿胡亂踢了幾下。",
    "抬起一條小腿伸在$N的臉上。",
    "高興地拍打著兩條小腿兒。",
    "扭了扭腰肢。",
    "撅了撅小屁屁。",
    "把小屁屁向$N一歪。",
    "笑了起來。",
    "咯咯咯笑個不停。",
    "摟著$N的脖子笑了起來。",
    "甜甜地一笑：叔叔阿姨，我要撒嬌嬌……",
    "天真地問：我撒個嬌嬌好不好呀？",
    "問$N：要是我撒個嬌嬌你是不是更喜歡我呀？",
    "突然開口說：咦，那個叔叔有小鬍子，我怎麼沒有呢？",
    "說：喲，阿姨頭髮真長，撓在寶寶的臉上癢癢耶。",
    "問道：小寶寶我什麼時候能長成大寶寶老寶寶？",
    "說道：阿姨，要不要聽我唱支歌？",
    "說道：寶寶想唱支兒歌，哪一支呢？我想不起來哪支最好聽的。",
    "嘟嘟囔囔地說：叔叔阿姨，我是個最好的小乖乖耶。",
    "一字一句地說：我最乖乖耶，叔叔阿姨只喜歡我一個小乖乖好嗎？",
    "自言自語地說：我是小乖乖，小乖乖是我。",
    "細聲細氣地說：小乖乖我……想吃糖糖耶。",
    "說：往我嘴裡放一顆糖糖好不好？",
    "說：叔叔阿姨能變魔術嗎？變出糖糖來好不好？",
  });

  string str1 = "$N"+rdm(dos)+"$n的"+rdm(parts)+"。\n";  
  string str2 = "$n"+rdm(actions)+"\n";
  
  if (arg != this_object()->query("id"))
  return 0;

  remove_call_out ("delayed_action");
  call_out ("delayed_action",1,str1,this_player(),this_object());
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",3,str2,this_player(),this_object());
  return 1;
}

int do_shua (string arg)
{
  object me = this_object();
  object who;
  string my_name = me->query("name");
  string *dos = ({
    "飛快地從$N手中跑下來，爬到$n的",
    "從$N身上滑下來，躥到$n的",
    "從$N手中使勁往$n身上一跳，貼在$n的",
    "朝$N點點頭，一轉身扒在$n的",
    "會意地爬到$n的",
    "老練地爬到$n的",
    "鬼鬼祟祟地蹦到$n的",
    "一個彈跳撲到$n的",
    "跳上$n的",
    "呼地一跳，躍在$n的",
    "一個小飛身躍在$n的",
    "身子一閃，已站在$n的",
    "巧巧地一翻身，抓在$n的",
    "機靈地抓在$n的",
  });

  string *parts = ({
    "後腦勺",
    "扁腦門",
    "亂頭髮",
    "禿頭",
    "水泡眼",
    "老鼠眼",
    "腮幫",
    "黃臉蛋",
    "厚嘴唇",
    "咧開的嘴巴",
    "肥耳朵",
    "大暴牙",
    "酒糟鼻子",
    "寬鼻梁",
    "肥下巴",
    "斜酒窩",
    "歪脖子",
    "瘦喉結",
    "塌肩膀",
    "雞胸",
    "短拇指",
    "肥掌",
    "左手",
    "右手",
    "胳膊肘",
    "瘦排骨",
    "小腿",
    "短腿",
    "大腿",
    "火柴棍大腿",
    "羅圈腿",
    "哈吧腿",
    "水桶腰",
    "南瓜腰",
    "水蛇腰",
    "水蘿蠻腰",
    "麻花腰",
    "搓板兒背",
    "腳後跟",
    "裹腳背",
    "大腳趾",
    "細腳肘",
    "大肚皮",
    "啤酒肥肚",
    "癟肚皮",
    "駝背",
    "肥臀",
    "臀尖",
  });

  string *actions = ({
    "不客氣地迅速尿了一小灘尿。",
    "端起小水槍就狂澆一氣。",
    "呸了一小口。",
    "吐出一小堆粘粘的口香糖渣。",
    "張口就舔了幾口。",
    "將$n舔得死去活來。",
    "張開小嘴咬了一口。",
    "張開小嘴咬住$n死死不放。",
    "咬下一小塊肉。",
    "咬下一大塊疙瘩肉。",
    "咬得$n捶胸頓足哭爹喊娘。",
    "咬出兩排紅牙印兒。",
    "咬出一大塊瘀血紫疤。",
    "揪下一撮毛。",
    "揪下一層老皮。",
    "扯住一撮細毛不放。",
    "硬是扯出一個血囊葫蘆。",
    "吧嗒吧嗒使勁捶了幾拳。",
    "捶出一個大囊腫。",
    "胡亂踢了幾下。",
    "踢得$n上吐下泄。",
    "砰地一聲踢中要害。",
    "踢得$n直翻白眼。",
    "用大腦袋轟地一撞。",
    "用小指扎出幾個繡花窟窿。",
    "使勁地抓出五道血痕。",
    "抓出五串水泡。",
    "伸出雙手玩命地一掐。",
    "咬牙切齒地掐住$n的人中。",
    "伸出手掐出好大一個腫塊。",
    "抓著盪秋千。",
    "啪啪左右開弓扇了十幾下。",
    "扇了個兩面紅。",
    "毫不客氣地撓起痒痒兒。",
    "撓出一大片粉頭痱子。",
    "用小手指摳出一小腫泡。",
    "用手指摳出一沙瘡。",
    "掏出一塊紅疤。",
    "抓出一大片青春美麗豆。",
  });

  string *returns = ({
    "然後跑回$N身上。",
    "然後悄悄地回到$N手中。",
    "再回頭一本正經地爬到$N身上。",
    "再縱身躍回到$N手中。",
    "再回頭一跳，躍到$N身上。",
    "然後高興地回到$N手中。",
    "然後得意地鑽回$N身上。",
    "然後十分滿意地鑽回$N手中。",
    "然後興奮地蹦回$N身上。",
    "然後欣喜若狂地蹦回$N手中。",
  });

  string str1 = my_name+rdm(dos)+rdm(parts)+"上，"+rdm(actions)+"\n";
  
  if (! arg)
    return 0;

  who = present(arg,environment(this_player()));

  if (! who)
  return notify_fail ("耍誰？\n");

  message_vision ("$N向"+my_name+
  "使了一個眼色，然後若無其事地看了$n一眼。\n",this_player(),who);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",3,str1,this_player(),who);
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",4,rdm(returns)+"\n",this_player(),who);
  return 1;
}

void delayed_action (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

void delayed_reaction (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

