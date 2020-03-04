#include <ansi2.h>
inherit NPC; 
void gotoinn();
void create()
{
        set_name(HIR"謎樣"NOR+WHT"老人"NOR,({"Quest oldman","oldman","man"}));
        set("long","一個滿頭白髮年過七旬的老人，據傳聞道只要能完成他的一個"HIC"願望\n"
                NOR"就能得到一輩子都想不到的好處•\n",);
        set("gender","男性");
        set("race", "人類");
        set("age", 70+random(5));
        set("title",HIY"一物千金"NOR);
        set("no_fight", 1);
set("schedule",
([
        "00" : (: gotoinn :),
    "05" : (: gotoinn :),
    "10" : (: gotoinn :),
    "15" : (: gotoinn :),
    "20" : (: gotoinn :),
]));
        setup();
} 


void gotoinn()
{
 int a=random(5);
        if(!find_object("/open/world1/tmr/area/hotel")) return;
        if(!find_object("/open/world1/cominging/area/hotel")) return;
        if(!find_object("/open/world1/acme/area/hotel")) return;
        if(!find_object("/open/world1/moonhide/area/hotel")) return;
        if(!find_object("/open/world1/wilfred/sand/room12")) return;
 message_vision("$N伸伸懶腰，緩緩的走了出去•\n", this_object());
 if( a == 0 ) {
   if( file_name(environment(this_object())) == "/open/world1/moonhide/area/hotel" ) a++;
   else this_object()->move("/open/world1/moonhide/area/hotel"); 
 }
 if( a == 1 ) {
   if( file_name(environment(this_object())) == "/open/world1/cominging/area/hotel" ) a++;
   else this_object()->move("/open/world1/cominging/area/hotel");
 } 
 if( a == 2 ) {
   if( file_name(environment(this_object())) == "/open/world1/acme/area/hotel" ) a++;
   else this_object()->move("/open/world1/acme/area/hotel");
 }
 if( a == 3 ) {
   if( file_name(environment(this_object())) == "/open/world1/tmr/area/hotel" ) a++;
   else this_object()->move("/open/world1/tmr/area/hotel");
 }
 if( a == 4 ) {
   if( file_name(environment(this_object())) == "/open/world1/wilfred/sand/room12" ) a=0;
   else this_object()->move("/open/world1/wilfred/sand/room12");
 }
 message_vision("$N伸伸懶腰，緩緩的走了進來•\n", this_object());
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_accept","accept");
        add_action("do_finish","finish");
        add_action("do_cancel","cancel"); 
        add_action("do_no_ask","ask");
        call_out("rb",15);
}
void greeting()
{
        object ob = this_player(),
               ob1 = new(__DIR__"red-envelope");
               
        command("peer "+ ob->query("id") );
        if ( ob ->query_temp("NewYear/Quest") > 0 ){
        command("say 這位" + RANK_D->query_respect(ob) + "拿到我想要的東西了嗎？");
        command("giggle"); 
        tell_object(ob,"(題示：請輸入"HIC"finish"NOR"完成任務)\n");        }
        if ( ob ->query("NewYear/EQGame") > 30 ){
        command("hmm");
        command("say 你幫了我那麼多忙，這是我的一點心意，請收下.."); 
        message_vision("$N拿出一個"+ob1->query("name")+"給$n•\n",this_object(),ob);
        ob->add("NewYear/EQGame",-30);
        ob1->move(ob);
        }
        return;
}

int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
} 
void relay_say(object me, string str)
{ 
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"願望") != -1)
  {
    if ( me ->query_temp("NewYear/Quest") < 1) {
    command("sigh");
    command("say 天下之物稀奇古怪，真希望能在闔眼前都能見過一次");
    tell_object(me,"(提示：請輸入"HIC"accept"NOR"接下他的請求)\n");
    } else {
    command("eh");
    command("say 還不快去找-.-");
    command("slap "+ me->query("id") );
    } 
  }
  return;
}

int do_accept()
{ 
object ob,me;
string name,*names,eq;

names  = ({
"/open/world1/ksj/lost_island/npc/eq/fire-wolf-surcoat",
"/open/world1/ksj/lost_island/npc/eq/crystal-shield",
"/open/world1/jangshow/flame_area/npc/obj/dragon-sword",
"/open/world1/ksj/east_island/npc/eq/red-armor",
"/open/world1/whoami/birdarea/npc/obj/hands",
"/open/world1/ksj/lost_island/npc/eq/purple-jade-ring",
"/open/world1/ksj/lost_island/npc/eq/brambly-crown",
"/open/world1/ksj/lost_island/npc/eq/jade-toad-wrists",
"/open/world1/ksj/east_island/npc/eq/lobster-wrists",
"/open/world1/ksj/east_island/npc/eq/garatsupa-necklace",
"/open/world1/ksj/east_island/npc/eq/ningyo-necklace",
"/open/world1/faceoff/sky/npc/eq/white_wrists",
"/open/world1/whoami/birdarea/npc/eq/bar-neck",
"/open/world1/whoami/birdarea/npc/eq/wit-neck",
"/open/world1/whoami/birdarea/npc/eq/fist3",
"/open/world1/moonhide/pool/npc/obj/sky-pearl",
"/open/world1/ksj/east_island/npc/eq/dragon-marking-waist",
"/open/world1/jangshow/flame_area/npc/obj/dragon-ring",
"/open/world1/ksj/east_island/npc/eq/angry-mask",
"/open/world1/tmr/advbonze/npc/eq/finger",
"/open/world1/moonhide/pool/npc/obj/snake-waist2",
"/open/world1/tmr/bagi/area/2f/npc/eq/mask",
"/open/world1/tmr/freezetaoism/npc/eq/tian-demon_cloak",
"/open/world1/ksj/east_island/npc/eq/cat-tail-waist",
"/open/world1/ksj/lost_island/npc/eq/silver-snake-waist",
"/open/world1/ksj/lost_island/npc/eq/leviathan-mask",
"/open/world1/ksj/lost_island/npc/eq/silver-dragon-claw",
"/open/world1/ksj/lost_island/npc/eq/huge-tiger-cloth",
"/open/world1/ksj/lost_island/npc/eq/inverse-horn-helmet",
"/open/world1/ksj/east_island/npc/eq/kilin-boots",
"/open/world1/ksj/east_island/npc/eq/orochi-cloak",
"/open/world1/ksj/east_island/npc/eq/orochi-leggings",
"/open/world1/ksj/east_island/npc/eq/orochi-shield",
"/open/world1/ksj/east_island/npc/eq/orochi-armor",
"/open/world1/ksj/east_island/npc/eq/orochi-gloves",
"/open/world1/ksj/east_island/npc/eq/orochi-mask",
"/open/world1/ksj/east_island/npc/eq/orochi-waist",
"/open/world1/ksj/east_island/npc/eq/viper-killed-katana",
"/open/world1/wilfred/sand/npc/eq/eq20",
"/open/world1/wilfred/sand/npc/eq/eq21",
"/open/world1/wilfred/sand/npc/eq/eq23",
"/open/world1/wilfred/sand/npc/eq/eq24",
"/open/world1/acme/area2/npc/wp/darksword", 
"/open/world1/acme/area/npc/eq/godarmor",
"/open/world1/acme/area2/npc/eq/shield",
"/open/world1/alickyuen/wind/wrists",
"/open/world1/eq/mf_armor",
"/open/world1/whoami/birdarea/npc/eq/f_waist",
"/open/world1/tmr/bagi/npc/eq/wu_pants",
"/open/world1/moonhide/area/under/npc/obj/evil-cloak",
"/open/world1/ksj/east_island/npc/eq/four-snake-surcoat",
"/open/world1/kkeenn/love/npc/obj/ten_pearl",
"/open/world1/eq/viper_cloth",
"/open/world1/tmr/ghost-forest/npc/wp/pike",
"/open/world1/wilfred/newbie/hammer", 
"/open/world1/tmr/area/npc/eq/heart_cloth",
"/open/world1/tmr/advthief/wp/tian-que_dagger",
"/open/world1/acme/area/npc/wp/sword2",
"/open/world1/wilfred/sand/npc/wp/wp1",
"/open/world1/acme/area/npc/wp/pike",
"/open/world1/eq/soldier_boots",
"/open/world1/eq/black_suit",
"/open/world1/acme/area2/npc/wp/axe2",
"/open/world1/acme/area2/npc/eq/boots",
"/open/world1/acme/area2/npc/eq/cloth",
"/open/world1/cominging/area/npc/eq/tg_boots",
"/open/world1/cominging/area/npc/eq/flyboots",
"/open/world1/wilfred/sand/npc/wp/wp5",
          }); 
name = names[random(sizeof(names))];  
  me = this_player();  
  ob = this_object(); 
eq = me->query_temp("NewYear/EQ");

  if ( me->query_temp("NewYear/Quest") < 1 && ob->query_temp("wait") < 1 )
  {
   command("say 終於有好心人想幫我了...");
   message_vision("$N說﹕$n去幫我找"+name->query("name")+"("+name->query("id")+")好了..\n"NOR,ob,me);
   me->set_temp("NewYear/EQ",name); 
   me->set_temp("NewYear/EQ1",name->query("id"));
   me->set_temp("NewYear/Quest",1);
   ob->set_temp("wait",2);
  } else if ( ob->query_temp("wait") > 1 ){
   command("whisper "+me->query("id")+" 你太猴急了！！");
  } else {
   message_vision("$N說﹕$n剛剛不是已經要幫我找"+eq->query("name")+"("+eq->query("id")+")了嗎？\n"NOR,ob,me);
   tell_object(me,"(提示：想取消任務請輸入"HIC"cancel"NOR")\n");
  }
return 1;
}

int do_cancel()
{
   object me,ob;
   me=this_player();
   ob=this_object();
   if ( me->query_temp("NewYear/Quest") > 0 )
   { 
    command("say 是嗎..那還真是遺憾..");
    me->delete_temp("NewYear"); 
   } else {
    command("? "+me->query("id"));
   }
return 1;
}

int do_finish()
{  
 object ob = this_object();
 object me = this_player();
 object ob1,ob2;
 string eqname,eqname1;
 int add;
 eqname1 = me->query_temp("NewYear/EQ1");
 eqname  = me->query_temp("NewYear/EQ");
 add = 1+random(4); 
  if ( me->query_temp("NewYear/Quest") > 0)
  {   
   if( objectp(ob1=present(eqname1,me)) && base_name(ob1) == eqname)
   {
    command("say 謝謝你啦..");
    message_vision("$N說﹕這"+ob1->query("unit")+"$n我就收下啦..\n",ob,ob1);
    tell_object(me,"(你做了好事，多積了"HIC+add+NOR"點的陰德。)\n");
    destruct(ob1);
    me->add("NewYear/EQGame",add);
    me->delete_temp("NewYear");
   } else {
    command("? "+me->query("id"));
   }
  } else {
    command("? "+me->query("id"));
  }
 return 1;
} 

int rb()
{ 
    string semote,*semotes;
semotes  = ({
"...","?","@@","ack",            
"addoil","agree","ant","arc","avert",            
"bag","baga","bandit","beep","bish",             
"bite","blush","bone","bow","buddha",           
"bye","cac","cat","ccc","chiachia",         
"coco","cold","come","comfort","cong",             
"consider2","cool","corpse","cow","crazy",            
"cross","cry","cute","dance","die","dog","drool","duel","dunno","eh","faint","fear","fish",
"flee",          
"flip","flog","flop","fool","gan",            
"ghost","giggle","good","grin","groan",          
"gy","hammer","hate","hehe","hello",          
"help!","hi","hmm","ho","hoho",           
"hug","idle","inn","jump","kick",           
"kiss","kneel","knife","know","kok",            
"la","lag","laugh","lick","light",          
"listen","love","ma","magic","melt",           
"mirror","miss","moan","monkey","moongirl",       
"moto","mouth","negative","no","nod",            
"nomatch","oh","oh?","ok","orz oldman",           
"pace","paper oldman","pat","peer","pickmou",        
"pig","pighead","pk","point","poke",           
"ponder","problem","puke","pushing","qqq",            
"really","robot","rock","roger","roll1",          
"sad","scream","shake","shiver","showtime",       
"sigh","sing","slap","sleep","slow",           
"sm","smile","smirk","snicker","snort",          
"sob","soga","song","sorry","spank",          
"spit","stare","study","sula","sun",            
"superlaugh","sweat","thank","think","tiger",          
"tsk","wa","wahaha","wait","walileh",    
"walk","wave","well","why","wine",           
"wink","ya","yawn","yo","zap","zzz",         
        });  
    semote = semotes[random(sizeof(semotes))];  
    delete_temp("wait");
    command(semote);
    return 1;
}
