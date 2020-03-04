#include <ansi2.h>
inherit NPC; 
void gotoinn();
void create()
{
        set_name(HIR"����"NOR+WHT"�ѤH"NOR,({"Quest oldman","oldman","man"}));
        set("long","�@�Ӻ��Y�վv�~�L�C�����ѤH�A�ڶǻD�D�u�n�৹���L���@��"HIC"�@��\n"
                NOR"�N��o��@���l���Q���쪺�n�B�E\n",);
        set("gender","�k��");
        set("race", "�H��");
        set("age", 70+random(5));
        set("title",HIY"�@���d��"NOR);
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
 message_vision("$N�����i�y�A�w�w�����F�X�h�E\n", this_object());
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
 message_vision("$N�����i�y�A�w�w�����F�i�ӡE\n", this_object());
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
        command("say �o��" + RANK_D->query_respect(ob) + "����ڷQ�n���F��F�ܡH");
        command("giggle"); 
        tell_object(ob,"(�D�ܡG�п�J"HIC"finish"NOR"��������)\n");        }
        if ( ob ->query("NewYear/EQGame") > 30 ){
        command("hmm");
        command("say �A���F�ڨ���h���A�o�O�ڪ��@�I�߷N�A�Ц��U.."); 
        message_vision("$N���X�@��"+ob1->query("name")+"��$n�E\n",this_object(),ob);
        ob->add("NewYear/EQGame",-30);
        ob1->move(ob);
        }
        return;
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
} 
void relay_say(object me, string str)
{ 
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�@��") != -1)
  {
    if ( me ->query_temp("NewYear/Quest") < 1) {
    command("sigh");
    command("say �ѤU�����}�_�j�ǡA�u�Ʊ��b�󲴫e���ਣ�L�@��");
    tell_object(me,"(���ܡG�п�J"HIC"accept"NOR"���U�L���ШD)\n");
    } else {
    command("eh");
    command("say �٤��֥h��-.-");
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
   command("say �ש󦳦n�ߤH�Q���ڤF...");
   message_vision("$N���R$n�h���ڧ�"+name->query("name")+"("+name->query("id")+")�n�F..\n"NOR,ob,me);
   me->set_temp("NewYear/EQ",name); 
   me->set_temp("NewYear/EQ1",name->query("id"));
   me->set_temp("NewYear/Quest",1);
   ob->set_temp("wait",2);
  } else if ( ob->query_temp("wait") > 1 ){
   command("whisper "+me->query("id")+" �A�ӵU��F�I�I");
  } else {
   message_vision("$N���R$n��褣�O�w�g�n���ڧ�"+eq->query("name")+"("+eq->query("id")+")�F�ܡH\n"NOR,ob,me);
   tell_object(me,"(���ܡG�Q�������Ƚп�J"HIC"cancel"NOR")\n");
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
    command("say �O��..���ٯu�O���..");
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
    command("say ���§A��..");
    message_vision("$N���R�o"+ob1->query("unit")+"$n�ڴN���U��..\n",ob,ob1);
    tell_object(me,"(�A���F�n�ơA�h�n�F"HIC+add+NOR"�I�����w�C)\n");
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
